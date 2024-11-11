#include <bits/stdc++.h>
using namespace std;
const int ma1 = 3e5 + 5;
string no = "NO", yes = "YES";
const unsigned int MOD = 1000000007;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  long long n, m;
  cin >> n >> m;
  string s[n], s1[m];
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  for (int j = 0; j < m; j++) {
    cin >> s1[j];
  }
  cin >> t;
  while (t--) {
    long long x;
    cin >> x;
    cout << s[(x - 1) % n] + s1[(x + 1) % m] << endl;
  }
}
