#include <bits/stdc++.h>
using namespace std;
map<int, int> A, B;
map<int, bool> K;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  int a;
  for (int i = 0; i < n; i++) {
    cin >> a;
    A[a]++;
    K[a] = true;
  }
  for (int i = 0; i < m; i++) {
    cin >> a;
    B[a]++;
    K[a] = true;
  }
  vector<int> v;
  for (typeof K.begin() it = K.begin(); it != K.end(); it++) {
    v.push_back(it->first);
  }
  reverse((v).begin(), (v).end());
  long long d = 0;
  for (int i = 0; i < v.size(); i++) {
    int A1 = A[v[i]], B1 = B[v[i]];
    if (A1 > B1 && A1 - B1 > d) {
      cout << "YES" << endl;
      return 0;
    } else if (A1 > B1) {
      d -= (A1 - B1);
    } else {
      d += (B1 - A1);
    }
  }
  cout << "NO" << endl;
  return 0;
}
