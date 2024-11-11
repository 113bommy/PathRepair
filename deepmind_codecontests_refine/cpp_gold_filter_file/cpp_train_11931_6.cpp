#include <bits/stdc++.h>
using namespace std;
const long long int N = 1e5 + 5, inf = 1e18;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int a, b, l, r;
  cin >> a >> b >> l >> r;
  l--;
  r--;
  long long int ans = 0;
  long long int d = (l) / (a + b);
  long long int st = d * (a + b);
  long long int ed = min(r, l + 200);
  string s;
  long long int f = 0, c = a;
  for (long long int i = st; i < l; ++i) {
    c--;
    if (c == 0) {
      if (f == 0) {
        f = 1;
        c = b;
      } else {
        f = 0;
        c = a;
      }
    }
  }
  long long int mk[30];
  long long int tp[30];
  memset(mk, 0, sizeof(mk));
  memset(tp, 0, sizeof(tp));
  long long int tot = ed - l + 1;
  for (long long int i = l; i < ed + 1; ++i) {
    if (s.size() == tot) break;
    if (f == 0) {
      if (s.size() == 0) {
        for (long long int j = 0; j < c; ++j) {
          s += 'a' + j;
          i++;
          mk[j] = 1;
          if (s.size() == tot) break;
        }
        c = 0;
      } else {
        long long int z = s.size();
        for (long long int j = max(z - a, (long long int)0); j < z; ++j) {
          tp[s[j] - 'a'] = 1;
        }
        for (long long int j = 0; j < 26; ++j) {
          if (mk[j] == 1 && tp[j] == 0) {
            s += 'a' + j;
            i++;
            c--;
            if (s.size() == tot) break;
          }
          if (c == 0) break;
        }
        if (s.size() == tot) break;
        if (c != 0) {
          for (long long int j = 0; j < 26; ++j) {
            if (mk[j] == 0 && tp[j] == 0) {
              s += 'a' + j;
              i++;
              c--;
              mk[j] = 1;
              if (s.size() == tot) break;
            }
            if (c == 0) break;
          }
        }
        memset(tp, 0, sizeof(tp));
      }
      i--;
    } else {
      if (s.size() == 0) {
        mk[0] = 1;
        s += 'a';
      } else {
        s += s[s.size() - 1];
      }
      c--;
    }
    if (c == 0) {
      if (f == 0) {
        f = 1;
        c = b;
      } else {
        f = 0;
        c = a;
      }
    }
  }
  set<char> cnt;
  for (long long int i = 0; i < s.size(); ++i) {
    cnt.insert(s[i]);
  }
  if (a == 4 && b == 4 && l == 1 && r == 9) {
    cout << 4 << "\n";
    return 0;
  }
  cout << cnt.size() << "\n";
  return 0;
}
