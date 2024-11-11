#include <bits/stdc++.h>
using namespace std;
void checkDefine();
string s;
bool check(char c) {
  return c == 'u' || c == 'e' || c == 'o' || c == 'a' || c == 'i';
}
int main() {
  cin >> s;
  long long int n = s.size();
  if (n <= 1) {
    if (check(s[0]) || s[0] == 'n') {
      cout << "YES";
      return 0;
    }
    cout << "NO";
    return 0;
  }
  for (int i = (0), _b = (n - 2); i <= _b; i++) {
    if (!check(s[i]) && s[i] != 'n') {
      if (!check(s[i + 1])) {
        cout << "NO";
        return 0;
      }
    }
  }
  if (check(s[n - 1]) || s[n - 1] != 'n') {
    cout << "NO";
    return 0;
  }
  cout << "YES";
  return 0;
}
void checkDefine() {
  long long int n, a[200005];
  map<long long int, long long int> m;
  cin >> n;
  for (int i = (0), _b = (n - 1); i <= _b; i++) {
    cin >> a[i];
    m[a[i]]++;
  }
  string s;
  cin >> s;
  {
    cout << "s"
         << " = ";
    cout << (s) << endl;
  };
  {
    cout << "a"
         << " = ";
    for (int _ = 0, _a = (n); _ < _a; _++) cout << a[_] << ' ';
    cout << endl;
  };
  {
    cout << "\"------------\""
         << " = ";
    cout << ("------------") << endl;
  };
  for (__typeof(m.begin()) it = m.begin(); it != m.end(); ++it) {
    cout << it->first << " " << it->second << endl;
  }
}
