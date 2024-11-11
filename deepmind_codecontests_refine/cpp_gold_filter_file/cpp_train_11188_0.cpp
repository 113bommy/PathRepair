#include <bits/stdc++.h>
using namespace std;
int main() {
  int q;
  cin >> q;
  string s[q], p[q];
  for (int i = 0; i < q; i++) {
    cin >> s[i] >> p[i];
  }
  int counter = 0;
  int a[q], flag = 0;
  for (int i = 0; i < q; i++) a[i] = 0;
  pair<int, int> w[q];
  int x;
  for (int i = 0; i < q; i++) {
    x = i;
    if (a[i] == 0) {
      a[i] = 1;
      for (int j = 0; j < q; j++) {
        if (p[x].length() == s[j].length() && a[j] == 0) {
          for (int k = 0; p[x][k] != '\0'; k++) {
            if (p[x][k] == s[j][k]) {
              flag = 0;
            } else {
              flag = 1;
              break;
            }
          }
          if (flag == 0) {
            a[j] = 1;
            x = j;
            j = 0;
          } else
            flag = 0;
        }
      }
      w[counter].first = i;
      w[counter].second = x;
      counter++;
    }
  }
  cout << counter << endl;
  for (int i = 0; i < counter; i++) {
    cout << s[w[i].first] << " " << p[w[i].second] << endl;
  }
}
