#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, m;
  double x;
  cin >> N >> m;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A[i] >> x;
  vector<int> V;
  for (int i = 0; i < N; i++) {
    int pos = upper_bound(V.begin(), V.end(), A[i]) - V.begin();
    if (pos == V.size()) {
      V.push_back(A[i]);
    } else {
      V[pos] = A[i];
    }
  }
  cout << N - V.size() << endl;
}
