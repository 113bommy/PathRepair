#include <bits/stdc++.h>
using namespace std;
int d(int n) {
  if (!n) return 1;
  int d = 0;
  while (n) {
    d++;
    n /= 10;
  }
  return d;
}
int n, k, m;
set<int> st;
set<int>::iterator it;
void prnt() {
  it = st.begin();
  for (int i = 0; i < m; i++) {
    printf("%08d\n", *it);
    it++;
  }
  exit(0);
}
void doit(int a, int b) {
  if (!b) {
    int diff = abs(abs(a) - k);
    if (diff >= 10000) return;
    if (d(diff * 10000 + n) <= 8) st.insert(diff * 10000 + n);
    if (d(n * 10000 + diff) <= 8) st.insert(n * 10000 + diff);
    if (st.size() >= m) prnt();
    return;
  }
  doit(a + b % 10, b / 10);
  doit(a - b % 10, b / 10);
  doit(a * (b % 10), b / 10);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> k >> m;
  for (int i = 0; true; i++) {
    n = i;
    doit(i % 10, i / 10);
  }
}
