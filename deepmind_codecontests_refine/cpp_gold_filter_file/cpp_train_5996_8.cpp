#include <bits/stdc++.h>
using namespace std;
int n, k, x, p = 0, k2;
vector<int> V;
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    V.push_back(i);
  }
  for (int i = 0; i < k; i++) {
    cin >> x;
    p = (p + x) % n;
    cout << V[p] << " ";
    V.erase(V.begin() + p);
    n--;
  }
}
