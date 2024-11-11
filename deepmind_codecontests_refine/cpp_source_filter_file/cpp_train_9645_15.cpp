#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[700] = {0};
  int n;
  cin >> n;
  int temp;
  for (int i = 0; i < n; i++) {
    cin >> temp;
    a[temp]++;
  }
  int cnt = 0;
  for (int i = 1; i < n; i++) {
    if (a[i] != 0) cnt++;
  }
  cout << cnt << endl;
}
