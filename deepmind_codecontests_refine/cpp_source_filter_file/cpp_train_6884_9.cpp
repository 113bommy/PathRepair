#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string s;
  cin >> s;
  long long int i, j, count = 0;
  for (i = 0; i < s.size(); i++)
    if (s[i] == '[')
      break;
    else
      count++;
  if (i > s.size() - 4) {
    cout << "-1" << endl;
    return 0;
  }
  i++;
  for (; i < s.size(); i++)
    if (s[i] == ':')
      break;
    else
      count++;
  if (i > s.size() - 3) {
    cout << "-1" << endl;
    return 0;
  }
  i++;
  for (j = s.size() - 1; i >= 0; i--)
    if (s[j] == ']')
      break;
    else
      count++;
  if (j <= i) {
    cout << "-1" << endl;
    return 0;
  }
  j--;
  for (; j >= 0; j--)
    if (s[j] == ':')
      break;
    else
      count++;
  if (j <= i) {
    cout << "-1" << endl;
    return 0;
  }
  j--;
  for (; i <= j; i++)
    if (s[i] != '|') count++;
  cout << s.size() - count << endl;
  return 0;
}
