#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long npc[3];
  long long n = 0;
  long long i, j, var;
  for (i = 0; i < 3; i++) {
    cin >> npc[i];
    n += npc[i];
  }
  long long pbc[n];
  for (i = 0; i < 3; i++) {
    for (j = 0; j < npc[i]; j++) {
      cin >> var;
      pbc[--var] = i;
    }
  }
  long long min_suffix[n + 1];
  {
    long long c2_to_c3 = 0;
    long long keep_c3 = 0;
    min_suffix[n] = npc[2];
    for (i = n - 1; i >= 0; i--) {
      if (pbc[i] == 1)
        ++c2_to_c3;
      else if (pbc[i] == 2)
        ++keep_c3;
      min_suffix[i] = min(npc[2] - keep_c3 + c2_to_c3, min_suffix[i + 1]);
    }
  }
  long long answer = npc[0] + min_suffix[0];
  long long keep_c1 = 0;
  long long c2_to_c1 = 0;
  for (i = 1; i <= n; i++) {
    if (pbc[i - 1] == 1)
      ++c2_to_c1;
    else if (pbc[i - 1] == 0)
      ++keep_c1;
    answer = min(answer, npc[0] - keep_c1 + c2_to_c1 + min_suffix[i]);
  }
  cout << answer;
  return 0;
}
