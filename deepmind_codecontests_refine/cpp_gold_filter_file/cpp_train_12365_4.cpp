#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto&& e : a) {
    cin >> e;
  }
  for (int i = k; i < n; i++) {
    cout << (a[i] > a[i - k] ? "Yes" : "No") << endl;
  }
}
