#include <bits/stdc++.h>
using namespace std;
const int inf = (int)1e9;
const double pi = acos(-1.0);
const double eps = 1e-9;
int n, a, b, fa, fb;
int main() {
  cin >> n >> a >> b;
  for (int i = 1; i <= a; i++)
    for (int j = 1; j <= b; j++)
      if ((i + j) & 1)
        fa++;
      else
        fb++;
  int pa = n / 2, push_back = n - n / 2;
  int cura = 2, curb = 1;
  if (fa >= pa && fb >= push_back) {
    for (int i = 1; i <= a; i++) {
      for (int j = 1; j <= b; j++) {
        if ((i + j) % 2 > 0 && pa > 0) {
          cout << cura << " ";
          cura += 2;
          pa--;
          continue;
          ;
        }
        if ((i + j) % 2 == 0 && push_back > 0) {
          cout << curb << " ";
          curb += 2;
          push_back--;
          continue;
        }
        cout << 0 << " ";
      }
      cout << endl;
    }
    return 0;
  }
  if (fb >= pa && fa >= push_back) {
    swap(pa, push_back);
    swap(cura, curb);
    for (int i = 1; i <= a; i++) {
      for (int j = 1; j <= b; j++) {
        if ((i + j) % 2 > 0 && pa > 0) {
          cout << cura << " ";
          cura += 2;
          pa--;
          continue;
          ;
        }
        if ((i + j) % 2 == 0 && push_back > 0) {
          cout << curb << " ";
          curb += 2;
          push_back--;
          continue;
        }
        cout << 0 << " ";
      }
      cout << endl;
    }
    return 0;
  }
  cout << -1;
  return 0;
}
