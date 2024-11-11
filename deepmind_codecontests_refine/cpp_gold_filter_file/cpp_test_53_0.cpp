#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
const long long mod = 1000000007;
int n;
char c;
string s;
bool b[300005];
vector<int> primes;
void MrUnknown() {
  int check = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] != c) {
      check = i + 1;
      break;
    }
  }
  if (!check) {
    cout << "0\n";
    return;
  }
  for (int i = n / 2; i < n; i++) {
    if (s[i] == c) {
      cout << "1\n" << i + 1 << "\n";
      return;
    }
  }
  cout << "2\n" << n << " ";
  for (int i = 2; i <= n; i++) {
    if (n % i != 0) {
      cout << i << "\n";
      return;
    }
  }
}
void inp() {
  cin >> n >> c >> s;
  MrUnknown();
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  for (int i = 2; i <= 3e5; i++) {
    if (!b[i]) {
      primes.push_back(i);
      for (int j = 2; j * i <= 3e5; j++) {
        b[j * i] = true;
      }
    }
  }
  int t;
  cin >> t;
  while (t--) inp();
}
