#include<bits/stdc++.h>
using namespace std;
int main()
{
  int A, B, C, D, E, F;
  cin >> A >> B >> C >> D >> E >> F;
  cout << A + B + C + D - min({A, B, C, D}) + max(E, F) << endl;
}