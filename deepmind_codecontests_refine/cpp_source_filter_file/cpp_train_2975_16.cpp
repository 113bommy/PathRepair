#include <bits/stdc++.h>
using namespace std;
void _make_Bin_V();
void PrintV();
unsigned long long int nCr(int n, int k);
bool chk(vector<int> v) {
  float mean = (v[0] + v[1] + v[2] + v[3]);
  float medi = 2 * (v[1] + v[2]);
  float rang = 4 * (v[3] - v[0]);
  return (mean == medi and medi == rang and rang == mean);
}
void sol() {
  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  cout << 3 << endl;
  cout << a + e - c << " " << b + c - d << endl;
  cout << a + c - e << " " << b + d - f << endl;
  cout << c + e - a << " " << d + f - b << endl;
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  sol();
}
void PrintV(const vector<int> v) {
  for (auto it = v.begin(); it != v.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;
}
unsigned long long int nCr(int n, int k) {
  unsigned long long int C[n + 1][k + 1];
  int i, j;
  for (i = 0; i <= n; i++) {
    for (j = 0; j <= min(i, k); j++) {
      if (j == 0 || j == i)
        C[i][j] = 1;
      else
        C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
    }
  }
  return C[n][k];
}
void _make_Bin_V() {
  int ptr = 0;
  for (int i = 0; i < pow(2, 15); i++) {
    std::string s = std::bitset<15>(i).to_string();
    reverse((s).begin(), (s).end());
  }
}
