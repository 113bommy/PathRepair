#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1000000007;
const long double EPS = 0.00000001;
long long int N, M, K, W, H, L, R;
long long int ans;
int main() {
  ios::sync_with_stdio(false);
  cin >> N;
  int num[2900];
  for (int i = 0; i < N * 2; i++) {
    cin >> num[i];
  }
  sort(num, num + N * 2);
  if (num[N / 2] == num[N / 2 + 1]) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
  }
  return 0;
}
