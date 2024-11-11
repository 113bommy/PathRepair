#include <bits/stdc++.h>
using namespace std;
namespace Patchouli {
string a[120];
multiset<string> s;
inline bool cmp(const string &a, const string &b) {
  return a.length() < b.length();
}
int QAQ() {
  string tmp;
  int n;
  cin >> n;
  if (n == 1) {
    cout << "? " << 1 << ' ' << 1 << endl;
    cin >> tmp;
    cout << "! " << tmp << endl;
    return false;
  }
  cout << "? " << 1 << ' ' << n << endl;
  for (int i = 1; i <= (n * (n + 1)) >> 1; ++i) {
    cin >> tmp;
    sort(tmp.begin(), tmp.end());
    s.insert(tmp);
  }
  cout << "? " << 2 << ' ' << n << endl;
  for (int i = 1; i <= (n * (n - 1)) >> 1; ++i) {
    cin >> tmp;
    sort(tmp.begin(), tmp.end());
    s.erase(s.find(tmp));
  }
  int cnt = 1;
  for (multiset<string>::iterator i = s.begin(); i != s.end(); ++i, ++cnt)
    a[cnt] = *i;
  sort(a + 1, a + n + 1, cmp);
  cout << "! ";
  for (int i = 1; i <= n; ++i) {
    for (string::iterator j = a[i].begin(); j != a[i].end(); ++j) {
      if (*j != '~') {
        cout << *j;
        for (int k = i + 1; k <= n; ++k) {
          for (string::iterator l = a[k].begin(); l != a[k].end(); ++l) {
            if (*j == *l) {
              *l = '~';
              break;
            }
          }
        }
        break;
      }
    }
  }
  cout << endl;
  return false;
}
}  // namespace Patchouli
int main() { return Patchouli::QAQ(); }
