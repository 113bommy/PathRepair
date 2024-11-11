#include <bits/stdc++.h>
using namespace std;
int main() {
  ios ::sync_with_stdio(0);
  cin.tie(0);
  string s1, s2, s3;
  const int size = 3;
  int flag;
  cin >> s1 >> s2 >> s3;
  for (int i = 0; i < size; i++) {
    if (s1[i] == '.' && s3[size - i] == '.') {
      continue;
    } else if (s1[i] == 'X' && s3[size - i] == 'X') {
      flag = 1;
      continue;
    } else {
      flag = 0;
      break;
    }
  }
  if (flag == 1) {
    if (s2[0] == 'X' && s2[2] == 'X') {
      flag = 1;
    } else if (s2[0] == '.' && s2[2] == '.') {
      flag = 1;
    } else {
      flag = 0;
    }
  }
  if (flag == 1) {
    cout << "YES";
  } else {
    cout << "NO";
  }
  return 0;
}
