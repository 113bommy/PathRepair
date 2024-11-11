#include <bits/stdc++.h>
using namespace std;
template <class T>
bool umin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool umax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
int ans[300009];
int arr[300009];
multiset<int> s;
int main() {
  int n, who = -1;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", arr + i);
    if (arr[i] == -1) who = i, arr[i] = 0;
    if (who == -1) arr[i] = 0;
  }
  int k = int(log2(n)), p = n - 2;
  long long ans = arr[n - 1];
  for (int i = k - 1; i >= 0; i--) {
    for (int j = 0; j < (1 << i); j++) {
      s.insert(arr[p--]);
    }
    int val = *s.begin();
    ans += val;
    s.erase(s.find(val));
  }
  printf("%d\n", ans);
  return 0;
}
