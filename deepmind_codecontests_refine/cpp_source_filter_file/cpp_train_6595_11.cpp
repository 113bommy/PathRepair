#include <bits/stdc++.h>
using namespace std;
pair<int, int> cal(int a, int b) {
  vector<int> v;
  pair<int, int> res(0, 0);
  while (b) {
    if (b > 1 || a == 1) {
      v.push_back(a / b);
      a %= b;
    } else {
      v.push_back(a - 1);
      a = 1;
    }
    res.first += v.back();
    res.second += v.back() - 1;
    swap(a, b);
  }
  if (a != 1) return pair<int, int>(-1, -1);
  return res;
}
void trace(int a, int b) {
  vector<int> v;
  while (b) {
    if (b > 1 || a == 1) {
      v.push_back(a / b);
      a %= b;
    } else {
      v.push_back(a - 1);
      a = 1;
    }
    swap(a, b);
  }
  char c = 'T';
  for (int i = int(v.size()) - 1; i >= 0; i--) {
    for (int j = 0; j < v[i]; j++) printf("%c", c);
    if (c == 'T')
      c = 'B';
    else
      c = 'T';
  }
  printf("\n");
}
int main() {
  int n, r;
  scanf("%d %d", &n, &r);
  int ans = 1 << 20, j;
  for (int i = 1; i < r; i++) {
    pair<int, int> t = cal(r, i);
    if (t.first == n && t.second < ans) {
      ans = t.second;
      j = i;
    }
  }
  if (ans <= n) {
    printf("%d\n", ans);
    trace(r, j);
  } else
    printf("IMPOSSIBLE\n");
  return 0;
}
