#include <bits/stdc++.h>
using namespace std;
vector<int> read_vi() {
  int n;
  cin >> n;
  vector<int> vs(n);
  for (int i = 0; i < n; ++i) {
    cin >> vs[i];
  }
  return vs;
}
vector<long long> read_vl() {
  int n;
  cin >> n;
  vector<long long> vs(n);
  for (int i = 0; i < n; ++i) {
    cin >> vs[i];
  }
  return vs;
}
int main() {
  vector<int> vs = read_vi();
  int m = vs[0];
  for (int i = 0; i < vs.size(); ++i) {
    if (vs[i] < m) {
      m = vs[i];
    }
  }
  cout << vs[1] + (m ^ vs[2]);
  return 0;
}
