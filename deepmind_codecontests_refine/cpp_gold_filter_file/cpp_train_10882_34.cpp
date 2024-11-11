#include <bits/stdc++.h>
using namespace std;
long long BigMod(long long B, long long P, long long M) {
  long long R = 1;
  while (P > 0) {
    if (P % 2 == 1) {
      R = (R * B) % M;
    }
    P /= 2;
    B = (B * B) % M;
  }
  return R;
}
bool vis[1000005];
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    int c;
    cin >> c;
    if (c <= 1000000) vis[c] = 1;
  }
  vector<int> v;
  int cost = 0, pos = 1;
  while (cost <= k) {
    if (vis[pos] == 0) {
      cost += pos;
      v.push_back(pos);
    }
    pos++;
  }
  cout << v.size() - 1 << "\n";
  for (int i = 0; i < v.size() - 1; i++) cout << v[i] << " ";
}
