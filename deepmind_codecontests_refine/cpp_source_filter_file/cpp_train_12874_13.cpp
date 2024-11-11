#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> a;
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    if (!x) a.push_back(x);
  }
  sort(a.begin(), a.end());
  auto re = unique(a.begin(), a.end());
  printf("%d", re - a.begin());
}
