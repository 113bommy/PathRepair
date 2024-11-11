#include <bits/stdc++.h>
long long MOD = 1000000007;
using namespace std;
bool sortbysec(const pair<long long, long long> &a,
               const pair<long long, long long> &b) {
  return (a.second < b.second);
}
long long POW(long long a, long long b) {
  if (b == 0) return 1;
  if (b == 1) return a % MOD;
  long long temp = POW(a, b / 2);
  if (b % 2 == 0)
    return (temp * temp) % MOD;
  else
    return (((temp * temp) % MOD) * a) % MOD;
}
vector<char> capl = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
                     'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
                     'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
vector<char> sml = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
                    'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
                    's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
vector<int> v[1000001];
int vis[1000001];
int main() {
  int n, x;
  cin >> n >> x;
  int a[n];
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  double mini = -1;
  long long i = n - 3, j = n - 1, k;
  while (i > 0) {
    if (a[j] - a[i] <= x) {
      double c = a[j] - a[i + 1], d = a[j] - a[i];
      double e = double(c) / d;
      mini = max(mini, e);
      i--;
    } else {
      if (j - i == 2) {
        j--;
        i--;
      } else {
        j--;
      }
    }
  }
  cout << setprecision(12) << mini;
}
