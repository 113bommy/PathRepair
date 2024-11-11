#include <bits/stdc++.h>
using namespace std;
int s[26];
int main() {
  char arr[1000];
  cin.getline(arr, 1000);
  string str = arr;
  int len = str.length();
  for (int i = 0; i < len; i++) {
    if (arr[i] >= 97 && arr[i] <= 122) {
      int x = (arr[i] - 97);
      s[x] = s[x] + 1;
    }
  }
  int count = 0;
  for (int i = 0; i < 26; i++) {
    if (s[i] != 0) {
      count++;
    }
  }
  cout << count;
}
