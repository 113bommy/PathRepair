#include <bits/stdc++.h>
using namespace std;
vector<int> a, b;
int n;
int main() {
  cin >> n;
  a.resize(n);
  b.resize(n);
  set<int> st;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b[i] = a[i];
  }
  sort(a.begin(), a.end());
  int k;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      if (b[i] == a[j]) k = j;
    k++;
    if (k >= n) k = 0;
    cout << a[k] << " ";
  }
}
