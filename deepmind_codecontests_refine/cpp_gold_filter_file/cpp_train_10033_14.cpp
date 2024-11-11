#include <bits/stdc++.h>
using namespace std;
int n, sum;
vector<int> v;
int a[10009], c[10009];
int main() {
  cin >> n;
  for (int i = 2; i <= 3000; i++) {
    for (int j = i + i; j <= 3100; j += i) {
      a[j] = 1;
    }
  }
  for (int i = 2; i <= 3000; i++) {
    if (!a[i]) v.push_back(i);
  }
  memset(a, 0, sizeof(a));
  for (int i = 0; i < v.size(); i++) {
    for (int j = v[i]; j <= 3100; j += v[i]) {
      a[j] = 1;
      c[j]++;
    }
  }
  v.clear();
  for (int i = 2; i <= 3100; i++) {
    if (!a[i]) v.push_back(i);
  }
  for (int i = 0; i < v.size(); i++) {
    for (int j = v[i]; j <= 3100; j += v[i]) c[j]++;
  }
  int sum = 0;
  for (int i = 2; i <= n; i++) {
    if (c[i] == 2) sum++;
  }
  cout << sum << endl;
  return 0;
}
