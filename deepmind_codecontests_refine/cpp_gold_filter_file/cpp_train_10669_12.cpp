#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int a[10000];
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    int s = 1;
    for (int j = 1; j <= n; j++) {
      if (a[j] > a[i]) s++;
    }
    cout << s << " ";
  }
  cout << "\n";
}
