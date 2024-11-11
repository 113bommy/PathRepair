#include <bits/stdc++.h>
using namespace std;
const int base = 1e9 + 7;
const int MAX_N = 4e5 + 4;
long long mark[1000];
void Solves() {
  long long n, M;
  cin >> n >> M;
  long long a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    long long ans = 0;
    long long hieu = M - a[i];
    for (int j = 1; j <= 10; j++) {
      long long k;
      k = min(mark[j], hieu / j);
      ans += k;
      hieu -= k * j;
    }
    mark[a[i]]++;
    cout << i - ans - 1 << " ";
  }
}
int main() {
  srand(time(NULL));
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  Solves();
}
