#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, a, b, k;
char str[N];
int main() {
  scanf("%d %d %d %d", &n, &a, &b, &k);
  scanf("%s", str);
  int cnt = 0;
  vector<pair<int, int> > pos;
  int possible = 0;
  for (int i = 0; str[i]; i++) {
    if (str[i] == '1') {
      if (cnt / b) {
        pos.push_back({i - cnt, cnt / b});
        possible += pos.back().second;
      }
      cnt = 0;
    } else {
      cnt++;
    }
  }
  if (cnt / b) {
    pos.push_back({n - cnt, cnt / b});
    possible += pos.back().second;
  }
  int shots = possible - a + 1;
  printf("%d\n", shots);
  for (auto cur : pos) {
    for (int i = 0; i < cur.second && shots; i++) {
      printf("%d ", cur.first + (i + 1) * b);
      shots--;
    }
  }
}
