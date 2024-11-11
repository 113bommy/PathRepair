#include <bits/stdc++.h>
using namespace std;
vector<int> V, B;
int main() {
  int n, d, a, p;
  cin >> n >> d;
  for (int i = 0; i < n; i++) {
    cin >> a;
    if (i == d - 1)
      p = a;
    else
      V.push_back(a);
  }
  cin >> a;
  p += a;
  for (int i = 1; i < n; i++) {
    cin >> a;
    B.push_back(a);
  }
  int l = 0;
  d = n;
  for (int i = V.size() - 1; i >= 0; i--) {
    for (; l < B.size(); l++)
      if (V[i] + B[l] < p) {
        d--;
        l++;
        break;
      }
  }
  cout << d;
  return 0;
}
