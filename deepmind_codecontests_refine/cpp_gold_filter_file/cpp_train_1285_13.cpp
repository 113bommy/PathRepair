#include <bits/stdc++.h>
using namespace std;
long long k, b, n, t, temp = 1, cnt = 0;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> k >> b >> n >> t;
  while (temp <= t) {
    cnt++;
    temp = k * temp + b;
  }
  cnt--;
  cnt = max(0LL, cnt);
  cout << max(0LL, n - cnt) << endl;
}
