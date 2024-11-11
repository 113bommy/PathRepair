#include <bits/stdc++.h>
using namespace std;

int main()
{
  int x, y, mon[] = {0, 2, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0};
  cin >> x >> y;
  cout << (mon[x - 1] == mon[y - 1] ? "Yes" : "No") << endl;
}