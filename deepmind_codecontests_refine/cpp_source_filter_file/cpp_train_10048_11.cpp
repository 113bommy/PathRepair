#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000;
int N;
int X[maxn], Y[maxn], O[maxn];
int maxY[maxn + 1], minY[maxn + 1];
int max2Y[maxn + 1], min2Y[maxn + 1];
bool compare(int a, int b) { return X[a] < X[b]; }
long long sq2(long long v) { return v * v; }
bool valid(long long m) {
  if (sq2(X[O[N - 1]] - X[O[0]]) <= m) {
    return true;
  }
  if (maxY[N] - minY[N] <= m) {
    return true;
  }
  for (int start = 0; start < N; start++) {
    int A = start, B = N;
    while (A + 1 != B) {
      int half = (A + B) / 2;
      if (sq2(X[O[half]] - X[O[start]]) <= m and
          abs(X[O[half]]) <= abs(X[O[start]])) {
        A = half;
      } else {
        B = half;
      }
    }
    int bigY = max(maxY[start], max2Y[A + 1]);
    int tinY = min(minY[start], min2Y[A + 1]);
    long long dis1 = sq2(bigY) + sq2(X[O[start]]);
    long long dis2 = sq2(tinY) + sq2(X[O[start]]);
    if (sq2(bigY - tinY) <= m) {
      if (dis1 <= m and dis2 <= m) {
        return true;
      }
    }
    int A2 = -1, B2 = start;
    while (A2 + 1 != B2) {
      int half = (A2 + B2) / 2;
      if (sq2(X[O[start]] - X[O[half]]) <= m and
          abs(X[O[half]]) <= abs(X[O[start]])) {
        B2 = half;
      } else {
        A2 = half;
      }
    }
    bigY = max(maxY[B2], max2Y[start + 1]);
    tinY = min(minY[B2], min2Y[start + 1]);
    dis1 = sq2(bigY) + sq2(X[O[start]]);
    dis2 = sq2(tinY) + sq2(X[O[start]]);
    if (sq2(bigY - tinY) <= m) {
      if (dis1 <= m and dis2 <= m) {
        return true;
      }
    }
  }
  return false;
}
void Solve() {
  long long A = -1;
  long long B = LONG_MAX;
  while (A + 1 != B) {
    long long half = (A + B) / 2;
    if (valid(half)) {
      B = half;
    } else {
      A = half;
    }
  }
  printf("%I64d\n", B);
}
void PreCalc() {
  maxY[0] = INT_MIN;
  minY[0] = INT_MAX;
  for (int i = 0; i < N; i++) {
    int v = O[i];
    maxY[i + 1] = max(maxY[i], Y[v]);
    minY[i + 1] = min(minY[i], Y[v]);
  }
  max2Y[N] = INT_MIN;
  min2Y[N] = INT_MAX;
  for (int i = N - 1; i > -1; i--) {
    int v = O[i];
    max2Y[i] = max(max2Y[i + 1], Y[v]);
    min2Y[i] = min(min2Y[i + 1], Y[v]);
  }
}
void Read() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d%d", &X[i], &Y[i]);
    O[i] = i;
  }
  sort(O, O + N, compare);
}
int main() {
  Read();
  PreCalc();
  Solve();
}
