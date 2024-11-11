#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 7;
inline void rvi(vector<int>& v, int n) {
  int temp;
  for (int i = 0; i < n; i++) {
    cin >> temp;
    v.push_back(temp);
  }
}
inline void rvll(vector<long long int>& v, int n) {
  long long int temp;
  for (int i = 0; i < n; i++) {
    cin >> temp;
    v.push_back(temp);
  }
}
inline void prvi(vector<int>& a) {
  for (int i = 0; i < a.size(); i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}
inline void prvll(vector<long long int>& a) {
  for (int i = 0; i < a.size(); i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}
inline void prmii(map<int, int>& m) {
  for (auto x : m) {
    cout << x.first << " " << x.second << endl;
  }
}
inline vector<long long int> prefixsum(vector<int>& a) {
  vector<long long int> b;
  b.push_back(a[0]);
  for (int i = 1; i < a.size(); i++) {
    b.push_back(a[i] + b[i - 1]);
  }
  return b;
}
inline vector<long long int> suffixsum(vector<int>& a) {
  vector<long long int> b((a.size()));
  b[(a.size()) - 1] = a[(a.size()) - 1];
  for (int i = (a.size()) - 1 - 1; i >= 0; i--) {
    b[i] = a[i] + b[i + 1];
  }
  return b;
}
inline vector<long long int> prefixsum(vector<long long int>& a) {
  vector<long long int> b;
  b.push_back(a[0]);
  for (int i = 1; i < a.size(); i++) {
    b.push_back(a[i] + b[i - 1]);
  }
  return b;
}
inline vector<long long int> suffixsum(vector<long long int>& a) {
  vector<long long int> b((a.size()));
  b[(a.size()) - 1] = a[(a.size()) - 1];
  for (int i = (a.size()) - 1 - 1; i >= 0; i--) {
    b[i] = a[i] + b[i + 1];
  }
  return b;
}
void solve();
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
void solve() {
  int t;
  cin >> t;
  while (t--) {
    int d;
    cin >> d;
    double a, b;
    if (d * d - 4 * d < 0) {
      cout << "N\n";
    } else {
      a = (d + sqrt(d * d - 4 * d)) / 2;
      b = d - a;
      printf("Y %.10lf %.10lf\n", a, b);
    }
  }
}
