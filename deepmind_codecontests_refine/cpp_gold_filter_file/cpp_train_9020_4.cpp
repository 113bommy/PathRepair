#include <bits/stdc++.h>
using namespace std;
map<int, int> M;
int A[200007];
int P[200007];
int R[200007];
int main() {
  int n;
  cin >> n;
  int sol = 0;
  for (int i = 1; i <= n; i++) cin >> A[i];
  for (int i = 1; i <= n; i++) {
    if (!M[A[i] - 1])
      P[i] = 1;
    else {
      P[i] = P[M[A[i] - 1]] + 1;
      R[i] = M[A[i] - 1];
    }
    M[A[i]] = i;
    sol = max(sol, P[i]);
  }
  int pos = 0;
  for (int i = 1; i <= n; i++) {
    if (P[i] == sol) pos = i;
  }
  stack<int> ans;
  while (pos) {
    ans.push(pos);
    pos = R[pos];
  }
  cout << ans.size() << '\n';
  while (!ans.empty()) {
    cout << ans.top() << ' ';
    ans.pop();
  }
}
