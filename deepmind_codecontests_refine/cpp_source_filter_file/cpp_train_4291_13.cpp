#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int main() {
  int numOfBlocks, white = 0, black = 0;
  string block;
  cin >> numOfBlocks >> block;
  for (int i = 0; i < numOfBlocks; i++) {
    if (block[i] == 'W')
      white++;
    else
      black++;
  }
  if (white == 0 || black == 0) {
    cout << 0;
    return 0;
  }
  if (white % 2 == 0 || black % 2 == 0) {
    int j;
    if (black % 2 != 0) {
      for (int i = 0; i < numOfBlocks; i++) {
        if (block[i] == 'W') {
          j = i + 1;
          while (block[j] != 'W') {
            v.push_back(j - 1);
            if (block[j - 1] == 'B')
              block[j - 1] = 'W';
            else
              block[j - 1] = 'B';
            if (block[j] == 'B')
              block[j] = 'W';
            else
              block[j] = 'B';
            j++;
          }
          v.push_back(j - 1);
          if (block[j - 1] == 'B')
            block[j - 1] = 'W';
          else
            block[j - 1] = 'B';
          if (block[j] == 'B')
            block[j] = 'W';
          else
            block[j] = 'B';
        }
      }
    } else {
      for (int i = 0; i < numOfBlocks; i++) {
        if (block[i] == 'B') {
          j = i + 1;
          while (block[j] != 'B') {
            v.push_back(j);
            if (block[j - 1] == 'B')
              block[j - 1] = 'W';
            else
              block[j - 1] = 'B';
            if (block[j] == 'B')
              block[j] = 'W';
            else
              block[j] = 'B';
            j++;
          }
          v.push_back(j);
          if (block[j - 1] == 'B')
            block[j - 1] = 'W';
          else
            block[j - 1] = 'B';
          if (block[j] == 'B')
            block[j] = 'W';
          else
            block[j] = 'B';
        }
      }
    }
    cout << v.size() << "\n";
    for (int i = 0; i < v.size(); i++) {
      cout << v[i] << " ";
    }
  } else {
    cout << -1;
    return 0;
  }
  return 0;
}
