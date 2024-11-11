#include <bits/stdc++.h>
using namespace std;
int x[200000], y[200000];
int main() {
  int n;
  scanf("%d\n", &n);
  for (int i = 0; i < n; i++) scanf("%d", &x[i]);
  for (int i = 0; i < n; i++) scanf("%d", &y[i]);
  set<int> s;
  for (int i = 0; i < n; i++) {
    s.insert(x[i]);
    s.insert(y[i]);
  }
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cnt += s.count(x[i] ^ y[i]);
    }
  }
  printf("%s\n", cnt % 2 ? "Koyomi" : "Karen");
  return 0;
}
