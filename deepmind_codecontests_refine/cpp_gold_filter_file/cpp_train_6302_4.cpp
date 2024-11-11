#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int main() {
  int n;
  string s;
  cin >> n;
  for (int i = 1; i <= 500; i++) {
    int q = 0, j = i;
    while (j) q *= 10, q += j % 10, j /= 10;
    while (q) v.push_back(q % 10), q /= 10;
    j = i;
    while (j % 10 == 0) v.push_back(0), j /= 10;
  }
  cout << v[n - 1];
}
