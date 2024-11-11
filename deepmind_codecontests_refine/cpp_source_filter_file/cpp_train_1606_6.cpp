#include <bits/stdc++.h>
using namespace std;
vector<int> v;
vector<int> a, b;
map<int, int> m;
bool A[100005];
bool B[100005];
int main() {
  ios_base::sync_with_stdio(0);
  ;
  int n, x, y;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    a.push_back(x);
    b.push_back(y);
    v.push_back(x);
    v.push_back(y);
  }
  sort((v).begin(), (v).end());
  for (int i = 0; i < v.size(); i++) {
    m[v[i]] = i;
  }
  int k = (n / 2);
  int lim = 2 * k;
  for (int i = 0; i < k; i++) {
    A[i] = 1;
    B[i] = 1;
  }
  for (int i = 0; i < n; i++) {
    if (m[a[i]] < lim) {
      A[i] = 1;
    }
    if (m[b[i]] < lim) {
      B[i] = 1;
    }
  }
  for (int i = 0; i < n; i++) {
    cout << A[i];
  }
  cout << "\n";
  for (int i = 0; i < n; i++) {
    cout << B[i];
  }
  cout << "\n";
  return 0;
}
