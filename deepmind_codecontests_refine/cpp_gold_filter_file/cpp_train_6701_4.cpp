#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const double eps = 1e-11;
int n, k;
vector<int> P;
vector<int> PINV;
vector<int> T;
vector<int> perm(vector<int> cur, vector<int> &MSK) {
  vector<int> res = cur;
  for (int i = 0; i < int((cur).size()); i++) {
    res[i] = cur[MSK[i]];
  }
  return res;
}
void pv(vector<int> v) {
  for (int i = 0; i < int((v).size()); i++) {
    cout << v[i] + 1 << " ";
  }
  cout << endl;
}
int main() {
  std::ios_base::sync_with_stdio(0);
  cin >> n >> k;
  P.resize(n);
  T.resize(n);
  PINV.resize(n);
  vector<int> cur;
  vector<int> org;
  for (int i = 0; i < n; i++) {
    cur.push_back(i);
    org.push_back(i);
    cin >> P[i];
    P[i]--;
  }
  for (int i = 0; i < n; i++) {
    cin >> T[i];
    T[i]--;
  }
  for (int i = 0; i < n; i++) {
    PINV[P[i]] = i;
  }
  if (cur == T) {
    cout << "NO\n";
    return 0;
  }
  bool eq = (P == PINV);
  for (int i = 1; i <= k; i++) {
    cur = perm(cur, P);
    if (cur == T) {
      if (i == k || (((k - i) % 2 == 0) && !eq)) {
        cout << "YES\n";
        return 0;
      } else
        break;
    }
  }
  cur = org;
  for (int i = 1; i <= k; i++) {
    cur = perm(cur, PINV);
    if (cur == T) {
      if (i == k || (((k - i) % 2 == 0) && !eq)) {
        cout << "YES\n";
        return 0;
      } else
        break;
    }
  }
  cout << "NO\n";
  return 0;
}
