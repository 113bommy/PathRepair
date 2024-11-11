#include <bits/stdc++.h>
using namespace std;
stack<long long> lstack;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long n, q;
  cin >> n >> q;
  while (q--) {
    int u;
    cin >> u;
    string str;
    cin >> str;
    while (!lstack.empty()) lstack.pop();
    long long size = n, cur = (size >> 1) + 1;
    while (cur != u) {
      lstack.push(cur);
      size >>= 1;
      if (u > cur)
        cur += (size >> 1) + 1;
      else
        cur -= (size >> 1) + 1;
    }
    for (int i = 0, j = str.size(); i < j; ++i) {
      if (str[i] == 'L') {
        if (size == 1) continue;
        lstack.push(cur);
        size >>= 1;
        cur -= (size >> 1) + 1;
      } else if (str[i] == 'R') {
        if (size == 1) continue;
        lstack.push(cur);
        size >>= 1;
        cur += (size >> 1) + 1;
      } else {
        if (size == n) continue;
        cur = lstack.top();
        size <<= 1;
        size++;
        lstack.pop();
      }
    }
    cout << cur << "\n";
  }
}
