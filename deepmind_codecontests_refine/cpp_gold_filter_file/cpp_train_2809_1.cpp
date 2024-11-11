#include <bits/stdc++.h>
using namespace std;

signed main()
{
  int A, B, C, D;
  
  while(cin >> A >> B >> C >> D, A || B || C || D) {
    cout << max(0, (B * C - A + D - 1) / D) << endl;
  }
  return 0;
}