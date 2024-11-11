#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  int n, m;
  cin >> n >> m;
  if (ceil(n / 2) <= m)
    cout << n - m << endl;
  else if (m == 0)
    cout << "1" << endl;
  else
    cout << m << endl;
  return 0;
}
