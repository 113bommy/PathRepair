#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007LL;
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int moves = 0;
  for (int i = 0; i < n - 1; i++) {
    long long t = log2(n - i - 1);
    long long factor = pow(2, t);
    moves += a[i];
    a[i + factor] += a[i];
    a[i] = 0;
    cout << moves << "\n";
  }
  return 0;
}
