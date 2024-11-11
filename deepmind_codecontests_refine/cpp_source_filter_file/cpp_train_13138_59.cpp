#include <bits/stdc++.h>
using namespace std;
const int NMax = 1000010;
int N;
char A[NMax];
int pi[NMax];
int maxim;
void Make_Pi() {
  int k = 0;
  pi[1] = 0;
  for (int i = 2; i <= N; ++i) {
    while (k > 0 && A[k + 1] != A[i]) k = pi[k];
    if (A[k + 1] == A[i]) ++k;
    pi[i] = k;
    if (i < N) maxim = max(maxim, pi[i]);
  }
}
int main() {
  std::ios_base::sync_with_stdio(false);
  cin >> (A + 1);
  N = strlen(A + 1);
  Make_Pi();
  if (pi[N] <= maxim || pi[pi[N]] <= maxim) {
    if (pi[N] == maxim)
      A[pi[N] + 1] = 0;
    else
      A[pi[pi[N]] + 1] = 0;
    if (A[1])
      cout << (A + 1) << "\n";
    else
      cout << "Just a legend\n";
    return 0;
  }
  cout << "Just a legend\n";
  return 0;
}
