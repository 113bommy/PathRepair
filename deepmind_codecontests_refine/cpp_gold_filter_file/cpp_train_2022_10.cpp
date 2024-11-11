#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e7 + 10;
int val[MAXN];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    int tmp = 0;
    for (int j = 0; j < 3; j++) tmp |= (1 << (s[j] - 'a'));
    val[tmp]++;
  }
  for (int i = 0; i < 24; i++) {
    for (int j = 0; j < (1 << 24); j++) {
      if (j & (1 << i)) val[j] += val[j - (1 << i)];
    }
  }
  int ans = 0;
  for (int i = 0; i < (1 << 24); i++) {
    int aux = n - val[i];
    ans ^= aux * aux;
  }
  cout << ans << endl;
  return 0;
}
