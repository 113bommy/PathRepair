#include <bits/stdc++.h>
using namespace std;
int tri(int n) {
  int pro[n - 1];
  pro[0] = 0;
  for (int i = 1; i < n - 2; i++) {
    pro[i] = (i + 1) * (i + 2) + pro[i - 1];
  }
  return pro[n - 2];
}
int main() {
  int n;
  cin >> n;
  cout << tri(n);
  return 0;
}
