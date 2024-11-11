#include <bits/stdc++.h>
using namespace std;
int N;
int a[100005];
bool Hash[1100005];
int Next[100005][20];
int main() {
  scanf("%d", &N);
  for (int i(1); i <= N; ++i) scanf("%d", &a[i]);
  for (int j(0); j < 20; ++j) Next[N + 1][j] = N + 1;
  for (int i(N); i; --i)
    for (int j(0); j < 20; ++j)
      Next[i][j] = ((a[i] >> j) & 1) ? i : Next[i + 1][j];
  for (int i(1); i <= N; ++i) {
    vector<pair<int, int> > Tmp;
    for (int j(0); j < 20; ++j) Tmp.push_back(make_pair(Next[i][j], j));
    sort(Tmp.begin(), Tmp.end());
    if (!a[i]) Hash[0] = 1;
    int Now = 0;
    for (int j(0); j < 20;) {
      if (Tmp[j].first == N + 1) break;
      Now |= 1 << Tmp[j].second;
      for (++j; j < 20 && Tmp[j].first == Tmp[j - 1].first; ++j)
        Now |= 1 << Tmp[j].second;
      Hash[Now] = 1;
    }
  }
  int Ans = 0;
  for (int i(0); i <= 1100000; ++i)
    if (Hash[i]) ++Ans;
  printf("%d\n", Ans);
}
