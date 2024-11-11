#include <bits/stdc++.h>
using namespace std;
struct operation {
  int i, j, x;
  operation(int i, int j, int x) {
    this->i = i;
    this->j = j;
    this->x = x;
  }
};
int mod(int a, int b) { return (a % b + b) % b; }
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    bool ok = true;
    vector<operation> operations;
    auto Report = [&](int i, int j, int x) {
      operations.emplace_back(i, j, x);
    };
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int sum = accumulate(a.begin(), a.end(), 0);
    if (sum % n != 0) {
      cout << "-1\n";
      continue;
    }
    int find = sum / n;
    for (int i = 1; i < n; i++) {
      int give = mod(-a[i], i + 1);
      Report(0, i, give);
      Report(i, 0, (a[i] + give) / (i + 1));
    }
    for (int i = 1; i < n; i++) {
      Report(0, i, a[i]);
    }
    cout << operations.size() << '\n';
    for (int i = 0; i < operations.size(); i++) {
      cout << operations[i].i + 1 << ' ' << operations[i].j + 1 << ' '
           << operations[i].x << '\n';
    }
  }
}
