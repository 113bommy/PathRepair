#include <bits/stdc++.h>
using namespace std;
int main() {
  int v[100001], n, count = 0;
  unsigned long long s = 0;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> v[i];
  sort(v, v + n);
  for (int i = 0; i < n; i++) {
    if (v[i] >= s) {
      s += v[i];
      count++;
    }
  }
  cout << count;
  return EXIT_SUCCESS;
}
