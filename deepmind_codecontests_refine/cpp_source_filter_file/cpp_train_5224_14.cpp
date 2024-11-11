#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  string memoria;
  vector<int> rooms(9, 0);
  cin >> n;
  cin >> memoria;
  for (int i = 0; i < memoria.size(); i++) {
    if (memoria[i] == 'L') {
      for (int j = 0; j < rooms.size(); j++) {
        if (rooms[j] == 0) {
          rooms[j] = 1;
          break;
        }
      }
    } else if (memoria[i] == 'R') {
      for (int j = 9; j >= 0; j--) {
        if (rooms[j] == 0) {
          rooms[j] = 1;
          break;
        }
      }
    } else {
      int num = memoria[i] - '0';
      rooms[num] = 0;
    }
  }
  for (int i = 0; i < rooms.size(); i++) {
    cout << rooms[i];
  }
  cout << endl;
  return 0;
}
