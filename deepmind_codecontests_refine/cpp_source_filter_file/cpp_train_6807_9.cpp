#include <bits/stdc++.h>
using namespace std;
using ii = pair<long long int, long long int>;
class prioritize {
 public:
  bool operator()(ii &p1, ii &p2) { return p1.first < p2.first; }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int n;
  cin >> n;
  if (n <= 2) {
    cout << -1 << "\n";
    return 0;
  }
  for (long long int i = 0; i < n; i++) {
    cout << i << " ";
  }
  cout << "\n";
  for (long long int i = 0; i < n; i++) {
    cout << i << " ";
  }
  cout << "\n";
  for (long long int i = 0; i < n; i++) {
    cout << (2 * i + n) % n << " ";
  }
  cout << "\n";
}
