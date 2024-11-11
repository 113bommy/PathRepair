#include <bits/stdc++.h>
using namespace std;
int IT_MAX = 1 << 18;
const long long MOD = 1000000009;
const int INF = 0x3f3f3f3f;
const long long LL_INF = 3234567890123456789ll;
const double PI = acos(-1);
const double EPS = 1e-8;
using namespace std;
bool chk[10];
bool isOdd(vector<int>& Vu, int X) {
  if (Vu.empty()) return false;
  printf("? %d ", (int)Vu.size());
  for (auto it : Vu) printf("%d ", it + 1);
  printf("\n");
  fflush(stdout);
  int t;
  scanf("%d", &t);
  int v = 0;
  if (Vu.size() % 2) v = X;
  return t != v;
}
int main() {
  int N, X, Y;
  scanf("%d %d %d", &N, &X, &Y);
  for (int i = 0; i < 10; i++) {
    vector<int> Vu;
    for (int j = 0; j < N; j++)
      if (j & (1 << i)) Vu.push_back(j);
    chk[i] = isOdd(Vu, X);
  }
  int p = 0;
  for (int i = 0; i < 10; i++)
    if (chk[i]) {
      p = i;
      break;
    }
  int a1 = 0, a2 = 1 << p;
  for (int i = 0; i < 10; i++) {
    if (i == p) continue;
    vector<int> Vu;
    for (int j = 1; j <= N; j++)
      if ((j & (1 << i)) && (j & (1 << p))) Vu.push_back(j);
    bool tc = isOdd(Vu, X);
    if (tc) a2 += (1 << i);
    if (tc ^ chk[i]) a1 += (1 << i);
  }
  if (a1 > a2) swap(a1, a2);
  printf("! %d %d\n", a1, a2);
  fflush(stdout);
}
