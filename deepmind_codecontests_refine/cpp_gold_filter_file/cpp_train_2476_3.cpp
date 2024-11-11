#include <bits/stdc++.h>
using namespace std;

int main()
{
  int A, B, C, D;
  cin >> A >> B >> C >> D;

  cout << ((A + D - 1) / D >= (C + B - 1) / B ? "Yes" : "No") << endl;
}
