#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
const long double PI = 3.14159265358979323846264338327;
const long long mx64 = 9223372036854775806;
const int mx32 = 2147483646;
const short int mx16 = 32766;
const long long mod1 = 1000000007;
const long long mod2 = 998244353;
const long long modh = 131333131;
void ITMO() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<vector<int>> b(n, vector<int>(30, 0));
  for (int i = 0; i < n; i++) {
    int aa = a[i];
    for (int j = 29; j >= 0; j--) {
      b[i][j] = aa % 2;
      aa /= 2;
    }
  }
  vector<int> cnt(30, 0);
  for (int j = 0; j < 30; j++) {
    int now = 0;
    for (int i = 0; i < n; i++) {
      now += b[i][j];
    }
    cnt[j] = now;
  }
  map<int, int> valind;
  for (int i = 0; i < n; i++) {
    int val = 0;
    int pw2 = 1;
    for (int j = 29; j >= 0; j--) {
      if (b[i][j] && cnt[j] == 1) {
        val += pw2;
      }
      pw2 *= 2;
    }
    valind[val] = i;
  }
  if (valind.size()) {
    int ANS = a[valind.rbegin()->second];
    for (int i = 0; i < n; i++) {
      if (a[i] != a[valind.rbegin()->second]) {
        swap(a[i], a[valind.rbegin()->second]);
        break;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout.precision(25);
  int t = 1;
  while (t--) {
    ITMO();
  }
  return 0;
}
