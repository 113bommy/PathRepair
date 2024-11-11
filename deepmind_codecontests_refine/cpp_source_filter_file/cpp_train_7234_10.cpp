#include <bits/stdc++.h>
using namespace std;
std::vector<int> v;
std::vector<int> s;
int main() {
  int n;
  int k;
  cin >> n;
  v.resize(n);
  s.resize(n);
  s[0] = 1;
  s[n - 1] = 1;
  for (int i = 0; i < n; ++i) {
    cin >> k;
    v[i] = k;
  }
  v[0] = 1;
  v[n - 1] = 1;
  int max = 0;
  for (int i = 1; i < n - 1; ++i) s[i] = min(v[i], s[i - 1] + 1);
  for (int i = n - 2; i > 0; i--) {
    v[i] = min(min(v[i], v[i + 1] + 1), s[i]);
    if (v[i] > max) max = v[i];
  }
  cout << max << endl;
}
