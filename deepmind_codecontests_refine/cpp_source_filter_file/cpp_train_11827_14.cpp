#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
const int M = 105;
const int inf = 1e9;
int a[N], n;
int ispossible(int middle) {
  vector<long long> ordered;
  for (int i = 0; i < n; ++i) {
    ordered.push_back(a[i] + (long long)(i + 1) * middle);
  }
  sort(ordered.begin(), ordered.end());
  long long need = 0;
  for (int i = 0; i < middle; ++i) {
    need += ordered[i];
  }
  return need;
}
int main() {
  int sum;
  scanf("%d %d", &n, &sum);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  int lower = 0, higher = n + 1;
  while (lower + 1 < higher) {
    int middle = (lower + higher) / 2;
    if (ispossible(middle) <= sum) {
      lower = middle;
    } else {
      higher = middle;
    }
  }
  cout << lower << " " << ispossible(lower) << endl;
  return 0;
}
