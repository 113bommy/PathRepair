#include <bits/stdc++.h>
using namespace std;
int n, m, maxi = 100005;
int A[100005];
int B[100005];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> A[i] >> B[i];
    maxi = min(maxi, B[i] - A[i]) + 1;
  }
  cout << maxi << endl;
  for (int i = 0; i < n; i++) {
    cout << i % maxi << " ";
  }
  cout << endl;
}
