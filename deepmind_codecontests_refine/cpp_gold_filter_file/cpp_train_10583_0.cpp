#include <bits/stdc++.h>
using namespace std;
char lower(char a) {
  if (a >= 'A' && a <= 'Z') return (a + 32);
  return a;
}
bool isGede(char a) {
  if (a >= 'A' && a <= 'Z') return true;
  return false;
}
int main() {
  int n;
  cin >> n;
  vector<string> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < v[i].length(); j++) {
      if (v[i][j] >= 'A' && v[i][j] <= 'Z') v[i][j] += 32;
    }
  }
  string w;
  cin >> w;
  char l;
  cin >> l;
  string ans = w;
  for (int i = 0; i < w.length(); i++) {
    char temp = w[i];
    if (temp >= 'A' && temp <= 'Z') temp += 32;
    for (int j = 0; j < v.size(); j++) {
      if (temp == v[j][0]) {
        int sama = 1;
        for (int k = 0; k < v[j].length(); k++) {
          if (lower(w[i + k]) != v[j][k]) {
            sama = 0;
            break;
          }
        }
        if (sama) {
          for (int k = 0; k < v[j].length(); k++) {
            if (lower(w[i + k]) == l) {
              if (lower(w[i + k]) == 'a') {
                if (isGede(w[i + k]))
                  ans[i + k] = ('b' - 32);
                else
                  ans[i + k] = 'b';
              } else {
                if (isGede(w[i + k]))
                  ans[i + k] = ('a' - 32);
                else
                  ans[i + k] = 'a';
              }
            } else {
              if (isGede(w[i + k]))
                ans[i + k] = (l - 32);
              else
                ans[i + k] = l;
            }
          }
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
