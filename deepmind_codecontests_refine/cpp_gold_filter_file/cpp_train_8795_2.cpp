#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 1e5 + 10;
const int INF = 1e9 + 10;
long long gcd(long long a, long long b) {
  if (!b) return a;
  return gcd(b, a % b);
}
vector<int> mas;
vector<long long> ans;
int main() {
  int n;
  cin >> n;
  mas = vector<int>(n);
  for (int i = 0; i < n; i++) cin >> mas[i];
  int max_i = 0, ans = 0;
  while (true) {
    for (int i = 0; i < n; i++) {
      if (mas[i] >= mas[max_i]) max_i = i;
    }
    if (!max_i)
      break;
    else {
      mas[max_i]--;
      mas[0]++;
      ans++;
    }
  }
  cout << ans;
}
