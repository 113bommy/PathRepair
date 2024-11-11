#include <bits/stdc++.h>
using namespace std;
int n;
int a[1000000];
int main() {
  cin >> n;
  int Max = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    Max = max(Max, a[i]);
  }
  long long s = 0;
  int i = 0;
  while (i < n) {
    s += Max - a[i];
    ++i;
  }
  cout << s;
  return 0;
}
