#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  string a, b;
  cin >> n >> a >> b;
  int both = 0, jmena = 0, jmenb = 0;
  for (int i = 0; i < a.size(); i++) {
    if (a[i] == '1' && b[i] == '1')
      both++;
    else if (b[i] == '1')
      jmenb++;
    else if (a[i] == '1')
      jmena++;
  }
  int cnt = 0;
  n = 2 * n;
  while (n) {
    if (n % 2 == 0) {
      if (both) {
        cnt++;
        both--;
      } else {
        if (jmena) {
          cnt++;
          jmena--;
        } else {
          jmenb--;
        }
      }
    } else {
      if (both) {
        cnt--;
        both--;
      } else {
        if (jmenb) {
          cnt--;
          jmenb--;
        } else {
          jmena--;
        }
      }
    }
    n--;
  }
  if (cnt == 0)
    cout << "Draw";
  else if (cnt > 0)
    cout << "First";
  else
    cout << "Second";
  return 0;
}
