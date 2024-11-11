#include <bits/stdc++.h>
using namespace std;
const long long M = 1e9 + 7;
void print(vector<long long> &a) {
  int n = a.size();
  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}
void print(vector<int> &a) {
  int n = a.size();
  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int te;
  te = 1;
  while (te--) {
    int n;
    cin >> n;
    vector<int> a(n), sol;
    sol.push_back(1);
    int sum = 0, coal = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      sum += a[i];
      if (i == 0)
        coal += a[i];
      else {
        if (a[0] >= 2 * a[i]) {
          sol.push_back(i + 1);
          coal += a[i];
        }
      }
    }
    if (2 * coal < sum) {
      cout << 0 << endl;
    } else {
      cout << sol.size() << endl;
      print(sol);
    }
  }
  return 0;
}
