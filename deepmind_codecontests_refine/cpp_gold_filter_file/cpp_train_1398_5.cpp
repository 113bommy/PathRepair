#include <bits/stdc++.h>
using namespace std;
long long ik, jk, il, jl, ans;
bool prof[10][10];
char c1, c2;
int main() {
  cin >> c1 >> c2;
  il = c2 - '0';
  jl = c1 - 'a' + 1;
  cin >> c1 >> c2;
  ik = c2 - '0';
  jk = c1 - 'a' + 1;
  ans = 0;
  for (int i = 1; i < 8; i++)
    for (int j = 1; j < 8; j++) prof[i][j] = false;
  prof[ik][jk] = true;
  for (int i = 1; i <= 8; i++)
    for (int j = 1; j <= 8; j++)
      if (i == il || j == jl) prof[i][j] = true;
  prof[ik - 2][jk + 1] = true;
  prof[ik - 2][jk - 1] = true;
  prof[ik + 2][jk + 1] = true;
  prof[ik + 2][jk - 1] = true;
  prof[ik + 1][jk + 2] = true;
  prof[ik + 1][jk - 2] = true;
  prof[ik - 1][jk + 2] = true;
  prof[ik - 1][jk - 2] = true;
  prof[il - 2][jl + 1] = true;
  prof[il - 2][jl - 1] = true;
  prof[il + 2][jl + 1] = true;
  prof[il + 2][jl - 1] = true;
  prof[il + 1][jl + 2] = true;
  prof[il + 1][jl - 2] = true;
  prof[il - 1][jl + 2] = true;
  prof[il - 1][jl - 2] = true;
  for (int i = 1; i <= 8; i++)
    for (int j = 1; j <= 8; j++)
      if (!prof[i][j]) ans++;
  cout << ans;
  return 0;
}
