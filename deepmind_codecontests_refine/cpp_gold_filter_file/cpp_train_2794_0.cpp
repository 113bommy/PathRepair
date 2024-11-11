#include <bits/stdc++.h>
using namespace std;

int main()
{
  int x, a, b;
  cin >> x >> a >> b;
  cout << (abs(x - a) < abs(x - b) ? "A" : "B") << endl;
}
