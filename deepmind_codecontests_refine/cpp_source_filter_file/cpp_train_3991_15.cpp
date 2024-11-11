#include <bits/stdc++.h>
using namespace std;
const int OST = 1000000007;
int a[105][2505];
string s;
int n;
void precalc() {
  memset(a, 0, sizeof(a));
  for (int i = 0; i < 26; i++) a[0][i] = 1;
  for (int i = 1; i < 101; i++) {
    for (int j = 0; j < 25 * (i + 1); j++) {
      for (int k = 0; (k < 26) && (k <= j); k++) {
        a[i][j] = (a[i][j] + a[i - 1][j - k]) % OST;
      }
    }
  }
}
int sum(string x) {
  int result = 0;
  for (int j = 0; j < (int)x.size(); j++) {
    result += (int)(x[j] - 'a');
  }
  return result;
}
int main() {
  precalc();
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    cin >> s;
    cout << a[s.size() - 1][sum(s)] - 1 << endl;
  }
  return 0;
}
