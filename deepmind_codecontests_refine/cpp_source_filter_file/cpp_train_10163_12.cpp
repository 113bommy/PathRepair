#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void debug(vector<T> v) {
  cout << "\ndebug(vector)\n";
  long long i;
  for (i = 0; i < v.size(); i++) cout << v[i] << " ";
  cout << "\n\n";
}
inline bool prime(long long n) {
  long long i;
  for (i = 2; i * i <= n; i++)
    if (n % i == 0) return false;
  return true;
}
void solve() {
  long long n;
  cin >> n;
  if (n == 1)
    cout << 1 << endl << 1;
  else
    cout << 2 * (n - 1) << " 2" << endl << "1 2";
}
int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
