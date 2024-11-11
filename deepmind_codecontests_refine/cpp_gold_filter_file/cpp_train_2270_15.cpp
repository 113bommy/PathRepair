#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s;
  int n, k;
  cin >> n >> k >> s;

  s[k-1] += 0x20;

  cout << s << endl;
}
