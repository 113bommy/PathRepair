#include <bits/stdc++.h>
using namespace std;
int a, n, k;
vector<int> V;
int go(vector<int> V, int b) {
  if (b < 0) return V.size();
  vector<int> v1;
  vector<int> v2;
  for (int i = 0; i < V.size(); i++) {
    if ((1 << b) & V[i])
      v1.push_back(V[i]);
    else
      v2.push_back(V[i]);
  }
  if (v1.size() <= 1 && v2.size() <= 1) return V.size();
  if (v1.size() <= 1) return v1.size() + go(v2, b - 1);
  if (v2.size() <= 1) return v2.size() + go(v1, b - 1);
  return max(go(v1, b - 1), go(v2, b - 1)) + 1;
}
int main() {
  cin >> n;
  for (k = 1; k <= n; k++) {
    cin >> a;
    V.push_back(a);
  }
  cout << n - go(V, 30);
}
