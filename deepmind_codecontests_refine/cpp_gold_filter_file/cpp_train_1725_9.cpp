#include <bits/stdc++.h>
using namespace std;
int cnt[300000];
int main() {
  ios_base::sync_with_stdio(0);
  int result = 0;
  int buffer = 0;
  int N, S;
  scanf("%d%d", &N, &S);
  for (int i = 0; i < (N); ++i) {
    int a;
    scanf("%d", &a);
    if (i == S - 1) {
      if (a != 0) ++result;
    } else if (a == 0) {
      ++result;
      ++buffer;
    } else
      ++cnt[a];
  }
  int maxi = 0;
  for (int i = (1); i < (N + 1); ++i) {
    if (cnt[i] == 0 && buffer > 0) {
      ++cnt[i];
      --buffer;
    }
    if (cnt[i] > 0) maxi = i;
  }
  for (int i = 1; i < maxi; ++i) {
    if (cnt[i]) continue;
    ++result;
    ++cnt[i];
    --cnt[maxi];
    while (!cnt[maxi]) --maxi;
  }
  printf("%d\n", result);
}
