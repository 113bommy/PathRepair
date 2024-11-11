#include <bits/stdc++.h>
using namespace std;
int N, K;
int ar[200005];
int grund[200005];
int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  for (int i = 1; i <= 60; i++) {
    for (int j = 1; (j * (j + 1)) / 2 <= i; j++) {
      grund[i] = j;
    }
  }
  int ans = 0;
  for (int i = 0; i < N; i++) {
    cin >> ar[i];
    ans ^= grund[ar[i]];
  }
  if (ans == 0)
    printf("YES\n");
  else
    printf("NO\n");
}
