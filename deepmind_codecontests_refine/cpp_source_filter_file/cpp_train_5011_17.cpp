#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d ", &n);
  string input;
  cin >> input;
  unordered_map<char, int> rgbMap;
  unordered_map<int, char> indexToGGB;
  rgbMap['R'] = 0;
  rgbMap['G'] = 1;
  rgbMap['B'] = 2;
  indexToGGB[0] = 'R';
  indexToGGB[1] = 'G';
  indexToGGB[2] = 'B';
  int changeCount = 0;
  for (int i = 1; i < input.size(); i++) {
    if (input[i] == input[i - 1]) {
      input[i] = indexToGGB[(rgbMap[input[i]] + 1) % 3];
      changeCount++;
      if (i + 1 < input.size() && input[i] == input[i + 1]) {
        input[i] = indexToGGB[(rgbMap[input[1]] + 1) % 3];
      }
    }
  }
  cout << changeCount << "\n";
  cout << input << "\n";
  return 0;
}
