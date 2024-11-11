#include <bits/stdc++.h>
using namespace std;
int main() {
  int height, width;
  cin >> height >> width;
  int i;
  char* row = (char*)malloc(width);
  int answer = 0;
  for (i = 0; i < height; i++) {
    cin >> row;
    if (i == height - 1) {
      int j;
      int last = 0;
      for (j = 0; j < width; j++) {
        if (row[j] == 'B' && last == 0) {
          answer++;
          last = 1;
        } else if (row[j] != 'B' && last == 1) {
          last = 0;
        }
      }
    }
  }
  cout << answer << endl;
  return 0;
}
