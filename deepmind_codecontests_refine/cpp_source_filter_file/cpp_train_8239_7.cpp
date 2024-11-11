#include <bits/stdc++.h>
int a[105];
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    sum += a[i];
  }
  vector<int> V;
  V.push_back(a[1]);
  int tmp = a[1];
  int sumtmp = a[1];
  for (int i = 2; i <= n; i++) {
    if (a[i] * 2 <= a[1]) {
      V.push_back(a[i]);
      sumtmp += a[i];
    }
  }
  if (sumtmp * 2 > sum) {
    cout << V.size() << endl;
    for (auto v : V) cout << v << ' ';
  } else {
    puts("0");
  }
  return 0;
}
