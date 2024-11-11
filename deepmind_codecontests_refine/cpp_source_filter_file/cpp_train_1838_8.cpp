#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cout.precision(12);
  long long p, k;
  cin >> p >> k;
  int d = 0;
  long long prod = 1;
  while (double(prod) * k < 2e18 && prod * k < p) {
    prod *= k;
    d++;
  }
  vector<long long> a;
  while (d >= 0) {
    a.push_back(p / prod);
    p -= a.back() * prod;
    d--;
    prod /= k;
  }
  std::reverse(a.begin(), a.end());
  for (int i = 1; i < a.size(); i += 2) {
    if (a[i] == 0) continue;
    a[i] -= k;
    int carry = i + 1;
    while (carry < a.size() && a[carry] == k - 1) {
      a[carry] = 0;
      carry++;
    }
    if (carry >= a.size()) {
      a.push_back(1);
    } else {
      a[carry]++;
    }
  }
  cout << a.size() << endl;
  for (int x : a) cout << std::abs(x) << ' ';
  cout << endl;
}
