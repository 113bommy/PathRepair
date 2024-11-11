#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int mas[n];
  set<int> b;
  for (int i = 0; i < n; i++) {
    cin >> mas[i];
    b.insert(mas[i]);
  };
  bool fw[n], bw[n];
  int nd = b.size();
  b.clear();
  for (int i = 0; i < n; i++) {
    int t = b.size();
    b.insert(mas[i]);
    fw[i] = (b.size() > t);
  }
  b.clear();
  for (int i = n - 1; i >= 0; i--) {
    int t = b.size();
    b.insert(mas[i]);
    bw[i] = (b.size() > t);
  }
  long long ct = 0;
  for (int i = 0; i < n; i++) {
    nd -= (int)bw[i];
    if (fw[i]) ct += nd;
  }
  cout << ct;
  return 0;
}
