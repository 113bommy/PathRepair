#include <bits/stdc++.h>
using namespace std;
int t, n, m, carac, acum;
int freq[2 * 100123], stop[2 * 100123], valor;
string s;
int main() {
  ios_base::sync_with_stdio(0);
  cin >> t;
  while (t--) {
    memset(stop, 0, sizeof(stop));
    memset(freq, 0, sizeof(freq));
    cin >> n >> m;
    cin >> s;
    for (int i = 0; i < m; i++) {
      cin >> valor;
      stop[valor - 1]++;
    }
    acum = 0;
    for (int i = n - 1; i >= 0; i--) {
      carac = s[i] - 'a';
      acum += stop[i];
      freq[carac] += (acum + 1);
    }
    for (int i = 0; i < 27; i++) {
      cout << freq[i] << (i == 26 ? "" : " ");
    }
    cout << endl;
  }
  return 0;
}
