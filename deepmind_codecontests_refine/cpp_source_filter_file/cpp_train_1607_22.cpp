#include <bits/stdc++.h>
using namespace std;
int main() {
  int l[3], ll[3], same = 0;
  cin >> l[0] >> l[1] >> l[2];
  cin >> ll[0] >> ll[1] >> ll[2];
  for (int i = 0; i < 3; i++)
    if (l[i] == ll[i]) same++;
  if (same >= 2)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
