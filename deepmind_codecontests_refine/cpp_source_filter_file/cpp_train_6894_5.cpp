#include <bits/stdc++.h>
using namespace std;
void Urvatullo_Atoev() {
  long long a, b, c, d, e = 0;
  string s;
  cin >> a;
  long long f[a];
  for (long long i = 0; i < a; i++) {
    cin >> b >> c;
    if (b % c == 0) {
      cout << "YES\n";
    } else {
      cout << "NO";
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  Urvatullo_Atoev();
  cerr << "\nInamika vakt-da kor kad: " << 1.0 * clock() / CLOCKS_PER_SEC
       << " s.\n";
}
