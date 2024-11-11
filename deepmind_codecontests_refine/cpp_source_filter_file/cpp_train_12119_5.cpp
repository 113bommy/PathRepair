#include <bits/stdc++.h>
using namespace std;
int N = 100001;
int main() {
  int n;
  int c = 0;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    int h;
    cin >> h;
    a[i] = h;
  }
  bool f = true;
  for (int i = 0; i < n; i++) {
    if (a[i] == i) c++;
    if (a[i] != i) {
      if (a[a[i]] == i && f) {
        c += 2;
        f = false;
      }
    }
  }
  if (f) {
    c += 1;
    f = false;
  }
  cout << c << endl;
}
