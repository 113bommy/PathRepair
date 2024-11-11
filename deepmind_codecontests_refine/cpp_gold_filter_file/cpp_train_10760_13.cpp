#include <bits/stdc++.h>
using namespace std;
map<long long, long long> M;
vector<long long> V;
int main() {
  ios_base::sync_with_stdio(false);
  long long n, d;
  cin >> n >> d;
  for (int k = 0; k < d; k++) {
    long long x;
    cin >> x;
    V.push_back(x);
    M[x]++;
  }
  for (int i = 0; i < d; i++) {
    cout << V[i] << " ";
    int cnt = 1;
    for (int k = 1; k <= n * d; k++) {
      if (cnt == n) break;
      if (M.count(k) <= 0) {
        M[k]++;
        cnt++;
        cout << k << " ";
      }
    }
    cout << endl;
  }
  return 0;
}
