#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n, r;
  cin >> n >> r;
  cout << (n < 10 ? r + (100 * (10 - n)) : r) << endl;
}