#include <bits/stdc++.h>
using namespace std;
int digit(int x, int pos) {
  for (int i = 0; i < int(pos); ++i) x /= 10;
  return x % 10;
}
vector<int> d10(6);
void genAll(int x, vector<int>* result) {
  for (int i = 0; i < int(4); ++i) {
    for (int j = 0; j < int(10); ++j) {
      if (i == 3 && j == 0) continue;
      result->push_back(x - digit(x, i) * d10[i] + j * d10[i]);
    }
  }
}
int main() {
  const int INF = 1000000;
  d10[0] = 1;
  for (int i = 1; i <= int(5); ++i) d10[i] = d10[i - 1] * 10;
  int n;
  cin >> n;
  vector<int> dates(n);
  for (int i = 0; i < int(n); ++i) cin >> dates[i];
  vector<int> d(n + 1);
  for (int i = 1; i <= int(n); ++i) {
    int x = dates[i - 1];
    vector<int> res;
    res.reserve(10000);
    genAll(x, &res);
    d[i] = INF;
    for (int j = 0; j < int(res.size()); ++j) {
      if (res[j] > d[i - 1] && res[j] < d[i]) d[i] = res[j];
    }
  }
  if (d[n] == INF || d[n] > 2011) {
    cout << "No solution" << endl;
    return 0;
  }
  for (int i = 1; i <= int(n); ++i) cout << d[i] << endl;
  return 0;
}
