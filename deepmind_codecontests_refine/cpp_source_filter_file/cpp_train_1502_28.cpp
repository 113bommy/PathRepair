#include <bits/stdc++.h>
using namespace std;
long long int c[3], vec[3];
bool burgue(long long int x, long long int &r,
            vector<long long int> &controle) {
  long long int a = r;
  for (int i = 0; i < 3; i++) {
    if (a / vec[i] + c[i] < x * controle[i])
      return false;
    else
      a -= 0 > (x * controle[i] - c[i]) * vec[i]
               ? 0
               : (x * controle[i] - c[i]) * vec[i];
  }
  return true;
}
int main() {
  string s;
  vector<long long int> controle(3, 0);
  while (cin >> s) {
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == 'B')
        controle[0]++;
      else if (s[i] == 'S')
        controle[1]++;
      else
        controle[2]++;
    }
    for (int i = 0; i < 3; i++) cin >> c[i];
    for (int i = 0; i < 3; i++) cin >> vec[i];
    long long int r;
    cin >> r;
    long long int l = 0, z = INT64_MAX, res;
    while (l <= z) {
      long long int m = (l + z) / 2;
      if (burgue(m, r, controle)) {
        res = m;
        l = m + 1;
      } else
        z = m - 1;
    }
    cout << res << endl;
  }
  return 0;
}
