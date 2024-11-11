#include <bits/stdc++.h>
using namespace std;
vector<int> a;
vector<int> dist(int idx, vector<int> v) {
  int cur = v[idx];
  vector<int> ret;
  v[idx] = 0;
  for (int i = 1; i <= 14; i++) {
    ret.push_back(v[(idx + i) % 14] + (cur / 14) + ((cur % 14) > (i - 1)));
  }
  return ret;
}
long long sum(vector<int> v) {
  long long ret = 0;
  for (int i = 0; i < 14; i++) ret += (v[i] * (v[i] & 1 ^ 1));
  return ret;
}
int main() {
  a.resize(14);
  for (int i = 0; i < 14; i++) cin >> a[i];
  long long out = 0;
  for (int i = 0; i < 14; i++) {
    out = max(out, sum(dist(i, a)));
  }
  cout << out << '\n';
  return 0;
}
