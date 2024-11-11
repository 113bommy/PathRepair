#include <bits/stdc++.h>
using namespace std;
bool cmp(const char& a, const char& b) { return a > b; }
int main() {
  int t;
  string s, ans;
  cin >> t;
  while (t--) {
    cin >> s;
    ans = "";
    int n = s.size(), need, aux;
    int mask = 0, p = 0, b = 0;
    for (int i = 0; i < n; i++) {
      int val = s[i] - '0';
      need = 0, aux = mask;
      while (aux > 0) {
        need += aux & 1;
        aux >>= 1;
      }
      if (need < n - i - 1 && val) {
        b = mask;
        p = i;
      } else if (need <= n - i && val) {
        for (int j = 0; j < val; j++)
          if ((1 << j) & mask) {
            b = mask;
            p = i;
            break;
          }
      }
      mask ^= (1 << val);
    }
    if (p == 0 && s[0] == '1') {
      for (int i = 0; i < n - 2; i++) {
        ans.push_back('9');
      }
      cout << ans << endl;
      continue;
    }
    for (int i = 0; i < p; i++) {
      ans.push_back(s[i]);
    }
    need = 0, aux = b;
    while (aux > 0) {
      need += aux & 1;
      aux >>= 1;
    }
    if (need < n - p - 1) {
      s[p]--;
    } else {
      for (int j = s[p] - '0' - 1; j >= 0; j--) {
        if ((1 << j) & b) {
          s[p] = j + '0';
          break;
        }
      }
    }
    b ^= (1 << (s[p] - '0'));
    ans.push_back(s[p]);
    need = 0, aux = b;
    while (aux > 0) {
      need += aux & 1;
      aux >>= 1;
    }
    for (int i = p + 1; i < n - need; i++) {
      ans.push_back('9');
    }
    for (int i = n - need; i < n; i++) {
      for (int k = 9; k >= 0; k--) {
        if ((1 << k) & b) {
          b ^= (1 << k);
          ans.push_back(k + '0');
        }
      }
    }
    cout << ans << endl;
  }
}
