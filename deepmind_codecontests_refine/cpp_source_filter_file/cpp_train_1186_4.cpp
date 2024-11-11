#include <bits/stdc++.h>
using namespace std;
set<int> ans;
void Print() {
  for (set<int>::iterator it = ans.begin(); it != ans.end(); it++) {
    printf("%08d\n", *it);
  }
  exit(0);
}
int k, m, no;
void goooo(int cur, int rem) {
  if (!rem) {
    int diff = abs(abs(cur) - k);
    if (diff > 10000) return;
    if (ans.size() < m) ans.insert(10000 * diff + no);
    if (ans.size() < m) ans.insert(no * 10000 + diff);
    if (ans.size() == m) {
      Print();
    }
    return;
  }
  goooo(cur + rem % 10, rem / 10);
  goooo(cur - rem % 10, rem / 10);
  goooo(cur * (rem % 10), rem / 10);
}
int main() {
  cin >> k >> m;
  for (int i = 0;; i++) {
    no = i;
    goooo(i % 10, i / 10);
  }
  return 0;
}
