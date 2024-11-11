#include <bits/stdc++.h>
using namespace std;
int main() {
  int count(string str);
  int count1, count2;
  string str1, str2;
  cin >> str1 >> str2;
  count1 = count(str1);
  count2 = count(str2);
  if ((count1) % 2 == 1) count1++;
  if (count1 >= count2)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
int count(string str) {
  int ones = 0;
  for (char i : str)
    if (i == '1') ones++;
  return ones;
}
