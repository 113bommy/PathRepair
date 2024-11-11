#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, arr[26];
  string str;
  memset(arr, sizeof(arr), 0);
  cin >> n >> str;
  for (int i = 0; i < str.size(); i++) arr[tolower(str[i]) - 'a']++;
  for (int i = 0; i < 26; i++)
    if (!arr[i]) {
      puts("NO");
      goto quit;
    }
  puts("YES");
quit:
  return 0;
}
