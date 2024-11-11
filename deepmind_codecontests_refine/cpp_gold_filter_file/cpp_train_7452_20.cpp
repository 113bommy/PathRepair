#include <bits/stdc++.h>
using namespace std;
long long max(long long a, long long b) { return a > b ? a : b; }
string tos(int n) {
  stringstream ss;
  ss << n;
  return ss.str();
}
const int NN = 55;
const long long MaxVal = 100000 + 1000;
vector<int> factor(int x) {
  vector<int> A, B;
  for (long long I = 1; I * I <= x; I++) {
    if (x % I == 0) {
      A.push_back(I);
      B.push_back(x / I);
    }
  }
  reverse(B.begin(), B.end());
  for (int i = 0; i < ((int)B.size()); i++) A.push_back(B[i]);
  return A;
}
bool okay(int m, int k) {
  vector<int> f = factor(m);
  for (int i = 0; i < ((int)f.size()); i++) {
    if (f[i] != m && f[i] >= k) return true;
  }
  return false;
}
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  if (!okay(m, k))
    cout << "Marsel" << endl;
  else {
    if (n & 1)
      cout << "Timur" << endl;
    else
      cout << "Marsel" << endl;
  }
  return 0;
}
