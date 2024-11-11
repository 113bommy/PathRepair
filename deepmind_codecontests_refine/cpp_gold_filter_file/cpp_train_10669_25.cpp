#include <bits/stdc++.h>
using namespace std;
vector<int> a;
int sup(int c, int n) {
  int x = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] > c) ++x;
  }
  return x;
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int f;
    cin >> f;
    a.push_back(f);
  }
  for (int i = 0; i < n; i++) cout << 1 + sup(a[i], n) << " ";
  return 0;
}
