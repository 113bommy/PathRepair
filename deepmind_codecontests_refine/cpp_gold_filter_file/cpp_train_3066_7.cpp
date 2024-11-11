#include <bits/stdc++.h>
using namespace std;
bool doesE(vector<string>& A, string& t) {
  for (int i = 0; i < A.size(); i++) {
    if (A[i] == t) return true;
  }
  return false;
}
int main() {
  ios ::sync_with_stdio(false);
  int n;
  cin >> n;
  int cnt;
  string t1, t2, t;
  vector<string> A;
  for (; n > 0; n--) {
    cin >> t1 >> t2;
    t = t1 + " " + t2;
    if (!doesE(A, t)) A.push_back(t);
  }
  cout << A.size();
  return 0;
}
