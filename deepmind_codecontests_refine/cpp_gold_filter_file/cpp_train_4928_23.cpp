#include <bits/stdc++.h>
using namespace std;
int n, a, b;
vector<int> l;
int main() {
  cin >> n >> a >> b;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    l.push_back(x);
  }
  sort(l.begin(), l.end());
  cout << l[b] - l[b - 1];
}
