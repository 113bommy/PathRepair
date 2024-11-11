#include <bits/stdc++.h>
using namespace std;
const double PI =
    3.14159265358979323846264338327950288419716939937510582097494459230;
bool comp(int a, int b) { return (a < b); }
int main() {
  int n;
  cin >> n;
  vector<long long> v(n), v1(n - 1), v2(n - 2);
  for (int i = 0; i < n; i++) cin >> v[i];
  for (int i = 0; i < n - 1; i++) cin >> v1[i];
  for (int i = 0; i < n - 2; i++) cin >> v2[i];
  sort(v.begin(), v.end());
  sort(v1.begin(), v1.end());
  sort(v2.begin(), v2.end());
  int i, c = 0;
  for (i = 0; i < n - 1; i++) {
    if (v[i] != v1[i]) {
      c = 1;
      break;
    }
  }
  if (c)
    cout << v[i] << "\n";
  else
    cout << v[n - 1] << "\n";
  int cc = 0;
  for (i = 0; i < n - 2; i++) {
    if (v1[i] != v2[i]) {
      cc = 1;
      break;
    }
  }
  if (cc)
    cout << v1[i];
  else
    cout << v1[n - 2];
  return 0;
}
