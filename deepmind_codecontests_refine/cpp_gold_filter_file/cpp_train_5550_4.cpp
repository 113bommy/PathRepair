#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  vector<pair<int, int> > vec;
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    vec.push_back({x, i});
  }
  sort(vec.begin(), vec.end());
  vector<int> A, B;
  long long suma = 0, sumb = 0;
  int i;
  for (i = n - 1; i >= 0; i--) {
    if (n & 1 && i == 0) break;
    if (i & 1) {
      A.push_back(vec[i].second);
      suma += vec[i].first;
    } else {
      B.push_back(vec[i].second);
      sumb += vec[i].first;
    }
  }
  if (i == 0) {
    int a = vec[0].second;
    long long b = vec[0].first;
    if (abs(suma - (sumb + a)) <= b) {
      B.push_back(a);
    } else {
      A.push_back(a);
    }
  }
  printf("%ld\n", A.size());
  for (int a : A) printf("%d ", a);
  printf("\n");
  printf("%ld\n", B.size());
  for (int b : B) printf("%d ", b);
  printf("\n");
  return 0;
}
