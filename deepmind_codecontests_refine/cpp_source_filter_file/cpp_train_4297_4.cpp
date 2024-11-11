#include <bits/stdc++.h>
using namespace std;
int find(string str, char vowel[], int k) {
  int count = 0;
  for (int i = str.size() - 1; i >= 0; i--) {
    char found = '0';
    for (int j = 0; j < 5; j++)
      if (str[i] == vowel[j]) {
        found = vowel[j];
        break;
      }
    if (found != '0') {
      count++;
      if (count == k) return i;
    }
  }
  return -1;
}
int main() {
  int n, k;
  cin >> n >> k;
  char vowel[5] = {'a', 'e', 'i', 'o', 'u'};
  int types[n];
  for (int i = 0; i < n; i++) {
    string found[4];
    for (int j = 0; j < 4; j++) {
      string str;
      cin >> str;
      int index = find(str, vowel, k);
      if (index == -1) {
        cout << "NO";
        return 0;
      }
      found[j] = str.substr(index, str.size() - index);
    }
    if (found[0] == found[1] && found[0] == found[1] && found[0] == found[3]) {
      types[i] = 4;
    } else if (found[0] == found[1] && found[2] == found[3])
      types[i] = 1;
    else if (found[0] == found[2] && found[1] == found[3])
      types[i] = 2;
    else if (found[0] == found[3] && found[1] == found[2])
      types[i] = 3;
    else {
      cout << "NO";
      return 0;
    }
  }
  int compare = 4;
  for (int i = 0; i < n; i++) {
    if (types[i] != 4) {
      if (compare != 4) {
        if (compare != types[i]) {
          cout << "NO";
          return 0;
        }
      } else
        compare = types[i];
    }
  }
  if (compare == 1)
    cout << "aabb";
  else if (compare == 2)
    cout << "abab";
  else if (compare == 3)
    cout << "abba";
  else if (compare == 4)
    cout << "aaaa";
}
