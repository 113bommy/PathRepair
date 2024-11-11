#include <bits/stdc++.h>
using namespace std;
int findCharacterIndex(char ch, string str) {
  for (int i = 0; i < str.length(); i++) {
    if (str[i] == ch) {
      return i;
    }
  }
  return -1;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n = 0, k = 0;
  string str;
  cin >> n >> k;
  cin >> str;
  int startIndex = findCharacterIndex('G', str);
  int targetIndex = findCharacterIndex('T', str);
  int currentIndex = startIndex;
  if (startIndex < targetIndex) {
    while (currentIndex < str.length()) {
      if (currentIndex == targetIndex || str[currentIndex] == '#') {
        break;
      }
      currentIndex += k;
    }
  } else {
    while (currentIndex >= 0) {
      if (currentIndex == targetIndex || str[currentIndex] == '#') {
        break;
      }
      currentIndex -= k;
    }
  }
  if (currentIndex != targetIndex) {
    cout << "NO";
  } else {
    cout << "YES";
  }
}
