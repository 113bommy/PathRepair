#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];
  sort((A).begin(), (A).end());
  A.erase(unique((A).begin(), (A).end()), A.end());
  N = A.size();
  vector<int> res;
  for (int i = 30; i >= 0; i--) {
    vector<int> tmp;
    vector<int> bits(31, 0);
    for (int j = 0; j < N; j++) {
      if (A[j] & (1 << i)) {
        tmp.push_back(A[j]);
      }
    }
    if (tmp.size()) {
      for (int j = 0; j < 31; j++) {
        bits[j] = (tmp[0] & (1 << j)) ? 1 : 0;
      }
      for (int j = 1; j < tmp.size(); j++) {
        for (int k = 0; k < i; k++) {
          int b = (tmp[j] & (1 << k)) ? 1 : 0;
          bits[j] &= b;
        }
      }
      bool can = true;
      for (int j = 0; j < 31; j++)
        if (bits[j] == 1) can = false;
      if (can) {
        res = tmp;
        break;
      }
    }
  }
  cout << res.size() << '\n';
  for (int i = 0; i < res.size(); i++)
    cout << res[i] << " \n"[i == res.size() - 1];
  return 0;
}
