#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long int n;
  vector<long long int> v;
  long long int a, s = 0;
  cin >> n;
  for (long long int i = 0; i < n; i++) {
    cin >> a;
    s += a;
    v.push_back(s);
  }
  for (long long int i = 0; i < n; i++) {
    if (2 * v[i] >= s) {
      cout << i + 1;
      break;
    }
  }
}
