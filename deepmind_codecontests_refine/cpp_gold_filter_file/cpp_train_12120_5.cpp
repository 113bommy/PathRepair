#include <bits/stdc++.h>
using namespace std;
long long int minn = 10001, maxx = -10001;
long long int n, m, k, dp[10001];
char c;
string second;
int main() {
  cin >> n >> m;
  long long int a[n];
  for (long long int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  for (long long int i = 0; i < n; i++)
    if (a[i] != a[(i + n / 2) % n]) k++;
  cout << k << endl;
  for (long long int i = 0; i < n; i++)
    cout << a[i] << " " << a[(i + n / 2) % n] << endl;
}
