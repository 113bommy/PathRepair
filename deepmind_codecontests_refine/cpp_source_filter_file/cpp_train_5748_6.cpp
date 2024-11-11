#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int ac = 1e6 + 5;
int A[ac], B[ac];
vector<int> C[ac];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) (cin >> A[i]), B[i] = A[i];
  sort(B, B + n, greater<int>());
  int h = 0, l = -1;
  for (int i = 0; i < n; i++) {
    if (l == B[i])
      h++;
    else
      h = 1, l = B[i];
    int j = 0, c = 0;
    vector<int> V;
    while (V.size() < i + 1) {
      if (c < h && A[j] == B[i])
        V.push_back(A[j]);
      else if (A[j] > B[i])
        V.push_back(A[j]);
      j++;
    }
    C[i] = V;
  }
  int m;
  cin >> m;
  while (m--) {
    int a, b;
    cin >> a >> b;
    cout << C[a - 1][b - 1] << '\n';
  }
}
