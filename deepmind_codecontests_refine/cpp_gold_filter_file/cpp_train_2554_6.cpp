#include <bits/stdc++.h>
using namespace std;
const int NMAX = 500005;
int v[NMAX], N, K;
bool ok1(int val) {
  int suma = 0;
  for (int i = 1; i <= N && v[i] < val; ++i) {
    if (v[i] < val) suma += val - v[i];
    if (suma > K) return false;
  }
  return true;
}
bool ok2(int val) {
  int suma = 0;
  for (int i = N; i >= 1 && v[i] > val; --i) {
    if (v[i] > val) suma += v[i] - val;
    if (suma > K) return false;
  }
  return true;
}
int main() {
  scanf("%d%d", &N, &K);
  long long sum = 0;
  for (int i = 1; i <= N; ++i) {
    scanf("%d", &v[i]);
    sum += v[i];
  }
  sort(v + 1, v + N + 1);
  int left = 1, right = 1e9, minim, maxim;
  while (left <= right) {
    int mid = (left + right) >> 1;
    if (ok1(mid)) {
      minim = mid;
      left = mid + 1;
    } else
      right = mid - 1;
  }
  left = 1;
  right = 1e9;
  while (left <= right) {
    int mid = (left + right) >> 1;
    if (ok2(mid)) {
      maxim = mid;
      right = mid - 1;
    } else
      left = mid + 1;
  }
  if (maxim <= minim)
    cout << !(sum % N == 0);
  else
    cout << maxim - minim;
  return 0;
}
