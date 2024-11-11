#include <bits/stdc++.h>
using namespace std;
int main(){
  int X,Y,res;
  cin >> X >> Y;
  if (X < 4) res += (4 - X) * 100000;
  if (Y < 4) res += (4 - Y) * 100000;
  if (X == 1 && Y == 1) res += 400000;
  cout << res;
}
