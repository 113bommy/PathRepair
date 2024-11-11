#include <bits/stdc++.h>
using namespace std;
long long int arr[501];
long long int c[31 * 501][600];
map<long long int, long long int> mp;
void primefactcalc(long long int n) {
  long long int no = 0;
  while (n % 2 == 0) {
    n = n / 2;
    no++;
  }
  if (no > 0) mp[2] += no;
  for (int i = 3; i * i <= n; i += 2) {
    no = 0;
    while (n % i == 0) {
      n /= i;
      no++;
    }
    if (no > 0) {
      mp[i] += no;
    }
  }
  if (n > 2) mp[n] += 1;
}
void init() {
  for (int i = 0; i < 31 * 501; i++) {
    for (int j = 0; j <= min(i, 500); j++) {
      if (i == 0 || j == i)
        c[i][j] = 1;
      else {
        c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % 1000000007;
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  init();
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
    primefactcalc(arr[i]);
  }
  long long int res = 1;
  for (auto it : mp) {
    long long int temp = it.second;
    res = (res * (c[N + temp - 1][N - 1])) % 1000000007;
  }
  cout << res << endl;
}
