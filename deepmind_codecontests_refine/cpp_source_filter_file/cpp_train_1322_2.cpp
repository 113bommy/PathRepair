#include <bits/stdc++.h>
const int MOD = 1e9 + 7;
using namespace std;
bool sortbysec(const pair<long long int, long long int> &a,
               const pair<long long int, long long int> &b) {
  return (a.second < b.second);
}
void solve() {
  long long int w, t;
  cin >> w >> t;
  long long int n;
  for (long long int i = 1; i <= 6; i++)
    if (i >= w && i >= t) n++;
  long long int b = 6;
  for (long long int i = 2; i <= 6; i++)
    if (n % i == 0 && b % i == 0) {
      n = n / i;
      b = b / i;
      break;
    }
  std::cout << n << "/" << b << std::endl;
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  { solve(); }
  cerr << "Timpe elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " mps\n";
  return 0;
}
