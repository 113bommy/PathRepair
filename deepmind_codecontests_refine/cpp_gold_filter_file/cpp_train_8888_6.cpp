#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long int n, count = 0;
  cin >> n;
  int a[n], b[n];
  for (int i = 0; i < n; i++) {
    int e1, e2;
    cin >> e1 >> e2;
    a[i] = e1;
    b[i] = e2;
  }
  for (int i = 0; i < n; i++) {
    bool flag = true;
    for (int j = 0; j < n; j++) {
      if (a[i] == b[j] && i != j) {
        flag = false;
        break;
      }
    }
    if (flag) count++;
  }
  cout << count;
}
