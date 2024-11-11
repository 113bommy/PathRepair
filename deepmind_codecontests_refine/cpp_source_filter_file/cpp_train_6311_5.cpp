#include <bits/stdc++.h>
using namespace std;
vector<long long> pref_sum_a;
vector<long long> pref_sum_b;
signed main() {
  long long n;
  cin >> n;
  if (n == 2) {
    cout << 3 << endl;
    cout << 2 << " " << 1 << " " << 2 << endl;
  }
  if (n == 3) {
    cout << 4 << endl;
    cout << 2 << " " << 1 << " " << 3 << " " << 2 << endl;
  }
  if (n == 4) {
    cout << 6 << endl;
    cout << 1 << " " << 3 << " " << 2 << " " << 4 << " " << 1 << " " << 2
         << endl;
  }
  if (n > 4) {
    cout << n + n / 2 << endl;
    for (long long t = 2; t <= n; t += 2) {
      cout << t << " ";
    }
    for (long long g = 1; g <= n; g += 2) {
      cout << g << " ";
    }
    for (long long t = 2; t <= n; t += 2) {
      cout << t << " ";
    }
  }
}
