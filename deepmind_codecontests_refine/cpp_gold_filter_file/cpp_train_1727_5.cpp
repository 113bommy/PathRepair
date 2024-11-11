#include <bits/stdc++.h>
using namespace std;
string f;
bool flag = false;
int main() {
  cin >> f;
  for (int i = 0, j = f.size() - 1; i < f.size(); i++, j--)
    if (f[i] == '8' && f[j] != '0' || f[i] == '5' && f[j] != '9' ||
        f[i] == '7' && f[j] != '7' || f[i] == '3' && f[j] != '3' ||
        f[i] == '1' && f[j] != '2' || f[i] == '4' && f[j] != '6')
      flag = true;
  flag ? cout << "No" << endl : cout << "Yes" << endl;
}
