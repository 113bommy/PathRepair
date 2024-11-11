#include <bits/stdc++.h>
using namespace std;
string alpha = "abcdefghijklmnopqrstuvwxyz";
string Alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string glas = "aeiou";
long long int Mod = pow(10, 9) + 7;
long long int ctoi(char x) {
  long long int xx = int(x) - 48;
  return xx;
}
long long int one = 1;
long long int null = 0;
int main() {
  iostream::sync_with_stdio(false);
  cin.tie(0);
  long long int n, z;
  cin >> n >> z;
  vector<long long int> v(n);
  for (long long int i = 0; i < n; i++) cin >> v[i];
  sort(v.begin(), v.end());
  long long int i = 0, j = 1;
  long long int curr = 10000000000, ans = 0;
  for (; j < n / 2; j++) {
    if ((v[j] - v[i]) >= z) curr = n - j - 1, i++, ans++;
    if (curr <= 0) break;
  }
  cout << ans;
}
