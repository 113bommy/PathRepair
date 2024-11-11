#include <bits/stdc++.h>
using namespace std;
struct floor {
  int k, f;
} v[1001];
int CheckPossibiltyFlat(int NumberOfFlats, int Floor, bool &IsGood) {
  if ((((v[Floor].k - 1) / NumberOfFlats) + 1) == v[Floor].f) {
    IsGood = true;
    return 1;
  } else {
    IsGood = false;
    return 0;
  }
}
int main() {
  int n, m, OneSolution, NumberOfSol = 0;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) cin >> v[i].k >> v[i].f;
  int i = 1;
  while (i < 100) {
    bool ok = true;
    for (int j = 1; j <= m; j++)
      if (CheckPossibiltyFlat(i, j, ok) == 0) break;
    if (ok == true) {
      int LocalSolution = ((n - 1) / i) + 1;
      NumberOfSol++;
      if (OneSolution != LocalSolution) {
        if (NumberOfSol > 1) {
          cout << -1;
          return 0;
        }
      }
      OneSolution = LocalSolution;
    }
    i++;
  }
  cout << OneSolution;
  return 0;
}
