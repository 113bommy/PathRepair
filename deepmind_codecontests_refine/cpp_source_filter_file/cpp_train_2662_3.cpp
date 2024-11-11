#include <bits/stdc++.h>
using namespace std;
int A[100005];
int main() {
  int n, a, b;
  cin >> n >> a >> b;
  for (int i = 1; i <= n; i++) cin >> A[i];
  cout << abs(A[a] - A[b]) << endl;
}
