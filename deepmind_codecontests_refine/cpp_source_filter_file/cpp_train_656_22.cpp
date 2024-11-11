#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int num = 0;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    num += a * a;
  }
  cout << num << endl;
  return 0;
}
