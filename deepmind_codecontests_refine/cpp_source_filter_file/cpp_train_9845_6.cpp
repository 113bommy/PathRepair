#include <bits/stdc++.h>
using namespace std;
int n, i, l, k, m, j;
string s;
int main() {
  cin >> n >> s;
  for (i = 0; i < n; i++)
    if (s[i] == 'A') l++;
  if (s[i] == 'D') j++;
  if (l > j)
    cout << "Anton";
  else if (j > l)
    cout << "Danik";
  else if (j == l)
    cout << "Friendship";
}
