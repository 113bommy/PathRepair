#include <bits/stdc++.h>
using namespace std;
int n, k, q, t, id;
long long A[1500001];
int T[150001];
int main() {
  cin >> n >> k >> q;
  set<long long> ID;
  for (int i = 1; i <= n; ++i) {
    cin >> A[i];
  }
  for (int i = 1; i <= q; i++) {
    cin >> t >> id;
    if (t == 1) {
      T[id] = 1;
      if (ID.empty() or ID.size() < k) {
        ID.insert(A[id]);
      } else if ((*ID.begin() < A[id]) and (ID.size() == k)) {
        ID.erase(ID.begin());
        ID.insert(A[id]);
      }
    } else {
      if (T[id] == 1 and ID.find(A[id]) != ID.end()) {
        cout << "Yes" << endl;
      } else {
        cout << "No" << endl;
      }
    }
  }
  return 0;
}
