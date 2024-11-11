#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s;
  int arr[4] = {0};
  for (int i = 0; i < 3; i++) {
    cin >> s;
    if (s[1] == '>')
      arr[s[0] - 'A']++;
    else
      arr[s[2] - 'A']++;
  }
  if (arr[0] == arr[1] && arr[1] == arr[2])
    return cout << "impossible" << endl, 0;
  char ss[3] = {""};
  ss[arr[0]] = 'A';
  ss[arr[1]] = 'B';
  ss[arr[2]] = 'C';
  cout << ss[0] << ss[1] << ss[2] << endl;
  return 0;
}
