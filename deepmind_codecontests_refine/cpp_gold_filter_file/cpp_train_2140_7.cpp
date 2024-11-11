#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
int N;
int M;
long long int CityPos[MAXN], TowerPos[MAXN];
bool Check(long long int R) {
  int j = 1;
  for (int i = 1; i <= M; i++) {
    while (CityPos[j] <= R + TowerPos[i] && j != N + 1 &&
           CityPos[j] >= TowerPos[i] - R) {
      j++;
    }
    if (j == N + 1) {
      return true;
    }
  }
  return false;
}
int main(void) {
  cin >> N >> M;
  for (int i = 1; i <= N; i++) {
    scanf("%lld", &CityPos[i]);
  }
  for (int i = 1; i <= M; i++) {
    scanf("%lld", &TowerPos[i]);
  }
  long long int l = 0;
  long long int r = 2e9;
  long long int ans = 0;
  while (l <= r) {
    long long int Mid = (l + r) / 2;
    if (Check(Mid)) {
      ans = Mid;
      r = Mid - 1;
    } else {
      l = Mid + 1;
    }
  }
  cout << l << endl;
  return 0;
}
