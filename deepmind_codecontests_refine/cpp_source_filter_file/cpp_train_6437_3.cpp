#include <bits/stdc++.h>

using namespace std;

int main()
{
  char S[100001];
  scanf("%s", s);
  
  int ans = strlen(S);
  int N = ans;
  
  for (int i = 0; i < N - 1; i++) {
    if (S[i] != S[i - 1]) ans = min(ans, max(i + 1, N - i - 1)));
  }
  
  printf("%d\n", ans);
  
  return 0;
}