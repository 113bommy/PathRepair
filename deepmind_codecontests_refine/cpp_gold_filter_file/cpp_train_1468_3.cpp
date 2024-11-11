#include <bits/stdc++.h>
using namespace std;
bool vo(char s) {
  int test = (int)s;
  if (test == 97 || test == 111 || test == 117 || test == 105 || test == 101)
    return true;
  return false;
}
bool no(char s) {
  int test = (int)s;
  if (s == 110) return true;
  return false;
}
int main() {
  string w;
  int i;
  cin >> w;
  if (w.size() == 1 && !no(w[0]) && !vo(w[0])) {
    cout << "NO";
    return 0;
  }
  for (i = 0; i < w.size(); i++) {
    if (!no(w[i])) {
      if (!vo(w[i])) {
        if (!vo(w[i + 1])) {
          cout << "NO";
          return 0;
        }
      }
    }
  }
  cout << "YES";
  return 0;
  return 0;
}
