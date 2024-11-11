#include <bits/stdc++.h>
using namespace std;
const int mxN = 1e6;
long long n, h[mxN + 10];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  long long s = 0;
  for (int i = 0; i < n; i++) cin >> h[i], s += h[i];
  long long t = n * (n - 1) / 2;
  for (int i = 0; i < n; i++)
    cout << i + (s - t) / n + (i < (s - t) % n) << " ";
  cout << '\n';
  return 0;
}
