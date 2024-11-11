#include <bits/stdc++.h>
using namespace std;
int main() {
  string x;
  cin >> x;
  bool f = 0;
  int en = x.size();
  int i;
  for (i = 0; i < en; i++) {
    if (x[i] == '@') {
      f = 1;
      break;
    }
  }
  if (f == 0) {
    cout << "NO\n";
    return 0;
  }
  int at = i;
  string un = x.substr(0, i);
  if (un.size() > 16 || un.size() < 1) {
    cout << "NO\n";
    return 0;
  }
  en = un.size();
  for (i = 0; i < en; i++) {
    if ((!(isalpha(un[i]))) && un[i] != '_' && (!(isdigit(un[i])))) {
      cout << "NO\n";
      return 0;
    }
  }
  en = x.size();
  for (i = at + 1; i < en; i++) {
    if (x[i] == '/') {
      break;
    }
  }
  int sl = i;
  string hn = x.substr(at + 1, i - at - 1);
  en = hn.size();
  for (i = 0; i < en; i++) {
    if ((!(isalpha(hn[i]))) && hn[i] != '_' && hn[i] != '.' &&
        (!(isdigit(hn[i])))) {
      cout << "NO\n";
      return 0;
    }
  }
  int ct = 0;
  for (i = 0; i < en; i++) {
    if (hn[i] != '.') {
      ct++;
    } else {
      if (ct > 16 || ct < 1) {
        cout << "NO\n";
        return 0;
      }
      ct = 0;
    }
  }
  if (ct > 16 || ct < 1) {
    cout << "NO\n";
    return 0;
  }
  en = x.size();
  ct = 0;
  for (i = sl + 1; i < en; i++) {
    ct++;
    if ((!(isalpha(x[i]))) && x[i] != '_' && (!(isdigit(x[i])))) {
      cout << "NO\n";
      return 0;
    }
  }
  if (sl + 1 == '\0') {
    cout << "NO\n";
    return 0;
  }
  if (ct > 16) {
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
}
