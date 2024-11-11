#include <bits/stdc++.h>
using namespace std;
int main() {
  string num;
  cin >> num;
  while (num[num.size() - 1] == '0') num.pop_back();
  int back = num.size() - 1;
  if (num.size() == 2) {
    if (num[0] == num[1])
      cout << "YES";
    else
      cout << "NO";
    return 0;
  }
  for (int i = 0; i < num.size() / 2; i++) {
    if (num[i] != num[back]) {
      cout << "NO";
      return 0;
    } else
      back--;
  }
  cout << "YES";
  return 0;
}
