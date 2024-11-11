#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long int LINF = 0x3f3f3f3f3f3f3f3fll;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 10;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ;
  int n, m;
  cin >> n;
  string st;
  cin >> st;
  int alfa[27];
  memset(alfa, -1, sizeof(alfa));
  int final = 'z' - 'a';
  for (int i = 0; i < n; i++) {
    int letter = st[i] - 'a';
    for (int j = letter + 1; j <= final; j++) {
      if (alfa[j] != -1) {
        cout << "YES" << endl;
        cout << alfa[j] << " " << i + 1 << endl;
        return 0;
      }
    }
    alfa[letter] = i + 1;
  }
  cout << "NO" << endl;
}
