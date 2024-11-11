#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int mid = 0, left = 0, right = 0;
  for (int i = 0; i < s.size(); i++)
    if (s[i] == '^') mid = i;
  for (int i = 0; i < mid; i++)
    if (s[i] != '=') left += (s[i] - '0') * (mid - i);
  for (int j = s.size() - 1; j > mid; j--)
    if (s[j] != '=') right += (s[j] - '0') * (j - mid);
  if (left > right)
    cout << "left";
  else if (left < right)
    cout << "right";
  else
    cout << "balance";
  return 0;
}
