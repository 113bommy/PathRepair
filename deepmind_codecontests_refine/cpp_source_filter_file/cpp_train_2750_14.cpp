#include <bits/stdc++.h>
using namespace std;
int main(int argc, char **argv) {
  int n;
  cin >> n;
  int a[1000];
  memset(a, 0, 4000);
  int l;
  int count = 0;
  int max = 0;
  for (int i = 0; i < n; i++) {
    cin >> l;
    if (a[l] == 0) count++;
    a[l]++;
    if (a[l] > max) max = a[l];
  }
  cout << max << ' ' << count;
  return 0;
}
