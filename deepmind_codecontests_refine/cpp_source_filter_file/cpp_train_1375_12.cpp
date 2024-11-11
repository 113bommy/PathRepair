#include <bits/stdc++.h>
using namespace std;
int N, A[200005], mid = 15, M1 = 30;
map<vector<int>, int> M;
vector<int> v;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  for (int i = 1; i <= N; i++) cin >> A[i];
  int b = (1 << mid) - 1;
  for (int i = 0; i <= b; i++) {
    v.clear();
    for (int j = 1; j <= N; j++) {
      int n = __builtin_popcount((A[j] & b) ^ i);
      v.push_back(n);
    }
    M[v] = i;
  }
  int a = (1 << M1) - 1 - b;
  for (int k = 0; k <= 30; k++) {
    for (int i = 0; i <= b; i++) {
      int mask = i << mid;
      v.clear();
      for (int j = 1; j <= N; j++) {
        int n = __builtin_popcount((A[j] & a) ^ mask);
        v.push_back(k - n);
      }
      if (M.find(v) != M.end()) {
        cout << M[v] + i << "\n";
        return 0;
      }
    }
  }
  cout << "-1\n";
}
