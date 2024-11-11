#include <bits/stdc++.h>
using namespace std;
string getParity(int b, int k, vector<int> a) {
  int par = a[k - 1] % 2;
  for (int i = 0; i < k - 1; ++i) {
    par = (par + a[i] * b) % 2;
  }
  return par == 1 ? "odd" : "even";
}
int main() {
  vector<int> a;
  int b, k;
  cin >> b >> k;
  for (int i = 0; i < k; ++i) {
    int val;
    cin >> val;
    a.push_back(val);
  }
  cout << getParity(b, k, a);
}
