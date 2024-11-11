#include <bits/stdc++.h>
using namespace std;
template <class T>
ostream& operator<<(ostream& fout, const vector<T>& vec) {
  for (const auto& el : vec) {
    fout << el << ' ';
  }
  return fout;
}
template <class T>
istream& operator>>(istream& fin, vector<T>& vec) {
  for (size_t i = 0; i < vec.size(); ++i) {
    cin >> vec[i];
  }
  return fin;
}
int Solve() {
  int n;
  cin >> n;
  vector<int> in(n);
  cin >> in;
  sort(in.begin(), in.end());
  in.push_back(90);
  int prev = 0;
  for (int i = 0; i <= n; ++i) {
    if (in[i] - prev > 15) {
      cout << prev + 15 << '\n';
      return 0;
    }
    prev = in[i];
  }
  cout << 90 << '\n';
  return 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  Solve();
  return 0;
}
