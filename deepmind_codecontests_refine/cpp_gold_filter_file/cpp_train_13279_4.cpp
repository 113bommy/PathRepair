#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7, oo = 1e9 + 7;
int a[6], q, b[5], c[6];
string s[N], ans[N], w[] = {"S",   "M",   "L",    "XL",     "XXL",     "XXXL",
                            "S,M", "M,L", "L,XL", "XL,XXL", "XXL,XXXL"};
int main(int argc, const char* argv[]) {
  for (int i = 0; i < 6; i++) cin >> a[i];
  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> s[i];
    int tmp;
    for (int j = 0; j < 11; j++)
      if (s[i] == w[j]) tmp = j;
    if (tmp > 5)
      b[tmp - 6]++;
    else {
      if (a[tmp] > 0)
        a[tmp]--;
      else {
        cout << "NO";
        return 0;
      }
      ans[i] = s[i];
    }
  }
  for (int i = 0; i < 6; i++) c[i] = a[i];
  for (int i = 0; i < 5; i++) {
    b[i] = max(0, b[i] - c[i]);
    if (b[i] > 0 && c[i + 1] < b[i]) {
      cout << "NO";
      return 0;
    }
    c[i + 1] -= b[i];
    b[i] = 0;
  }
  cout << "YES\n";
  for (int i = 0; i < 5; i++)
    for (int j = 0; j < q; j++)
      if (s[j] == w[6 + i]) {
        if (a[i] > 0) {
          a[i]--;
          ans[j] = w[i];
        } else {
          a[i + 1]--;
          ans[j] = w[i + 1];
        }
      }
  for (int i = 0; i < q; i++) cout << ans[i] << '\n';
  return 0;
}
