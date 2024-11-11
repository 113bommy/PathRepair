#include <bits/stdc++.h>
using namespace std;
struct customComparator {
  bool operator()(const int& lhs, const int& rhs) const { return true; }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, k;
  cin >> n >> k;
  if ((n / k) % 2 == 0) {
    cout << "NO" << '\n';
  } else {
    cout << "YES" << '\n';
  }
  return 0;
}
