#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int of = 0;
  int count = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == -1) {
      if (of == 0)
        count++;
      else
        of--;
    } else
      of += a[i];
  }
  cout << count;
}
