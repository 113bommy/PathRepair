#include <bits/stdc++.h>
using namespace std;
const int N = 100100;
int c[N];
vector<int> D[N];
int last[N];
int main() {
  memset(last, -1, sizeof(last));
  for (int i = 1; i < N; i++)
    for (int j = i; j < N; j += i) D[j].push_back(i);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    int Ans = 0;
    for (auto z : D[x])
      if (last[z] < y) Ans++;
    printf("%d\n", Ans);
    for (auto z : D[x]) last[z] = i;
  }
}
