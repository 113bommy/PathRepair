#include <bits/stdc++.h>
using namespace std;
const int N = 100;
const int oo = 1000;
vector<int> res;
int n, a, b, k;
int cnt;
char A;
int main() {
  scanf("%d %d %d %d", &n, &a, &b, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%c", &A);
    if (A == '1')
      cnt = 0;
    else {
      cnt++;
      if (cnt == b) res.push_back(i), cnt = 0;
    }
  }
  cnt = res.size();
  cnt -= a - 1;
  if (cnt < 0) cnt = 0;
  printf("%d\n", cnt);
  for (int i = 0; i < cnt; i++) printf("%d ", res[i]);
}
