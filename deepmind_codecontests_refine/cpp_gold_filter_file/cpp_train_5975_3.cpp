#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
const int mod = 1e9 + 7;
const int B = 317;
long long n;
long long a[N];
long long b[N];
pair<long long, long long> s[N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> s[i].first;
    s[i].second = i;
  }
  sort(s + 1, s + n + 1);
  int k = n - (n + 2) / 3;
  int f = 0;
  for (int i = n - k; i <= n; i++) {
    if (f % 2) {
      a[s[i].second] = f / 2;
      b[s[i].second] = s[i].first - f / 2;
    } else {
      a[s[i].second] = s[i].first - f / 2;
      b[s[i].second] = f / 2;
    }
    f++;
  }
  for (int i = 1; i < n - k; i++) {
    a[s[i].second] = 0;
    b[s[i].second] = s[i].first;
  }
  cout << "YES\n";
  for (int i = 1; i <= n; i++) cout << a[i] << " ";
  cout << "\n";
  for (int i = 1; i <= n; i++) cout << b[i] << " ";
}
