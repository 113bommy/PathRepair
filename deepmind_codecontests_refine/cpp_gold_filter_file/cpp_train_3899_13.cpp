#include <bits/stdc++.h>
using namespace std;
int a[3001];
int main() {
  int n, v;
  cin >> n >> v;
  long int s = 0;
  for (int i = 0; i < n; ++i) {
    int f, b;
    cin >> f >> b;
    a[f] = a[f] + b;
  }
  for (int i = 1; i < 3005; ++i) {
    s = s + min(a[i], v);
    a[i] = a[i] - min(a[i], v);
    a[i + 1] = a[i + 1] + min(a[i], v);
  }
  cout << s << endl;
}
