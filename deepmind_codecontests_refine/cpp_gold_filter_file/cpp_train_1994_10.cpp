#include <bits/stdc++.h>
using namespace std;
int main() {
  int a;
  cin >> a;
  vector<int> A;
  set<int> B;
  for (int i = 0; i < a; i++) {
    int x;
    cin >> x;
    if (!B.count(x)) {
      A.push_back(x);
      B.insert(x);
    }
  }
  sort(A.begin(), A.end());
  if (A.size() > 3) {
    cout << -1;
    return 0;
  }
  if (A.size() == 2 && (A[1] - A[0]) % 2 == 1) {
    cout << A[1] - A[0];
    return 0;
  }
  if (A.size() == 2) {
    cout << (A[1] - A[0]) / 2;
    return 0;
  }
  if (A.size() == 1) {
    cout << 0;
    return 0;
  }
  if (A[2] - A[1] != A[1] - A[0]) {
    cout << -1;
    return 0;
  }
  cout << (A[2] - A[0]) / 2;
}
