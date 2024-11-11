#include <bits/stdc++.h>
using namespace std;
struct point {
  long long x, y;
};
int Needed[4];
int exsist[4];
bool done() {
  for (int i = 0; i < 4; ++i) {
    if (Needed[i]) return false;
  }
  return true;
}
int main() {
  int t, length;
  point start, end;
  cin >> t;
  cin >> start.x >> start.y >> end.x >> end.y;
  Needed[0] = end.x > start.x ? end.x - start.x : 0;
  Needed[1] = start.y > end.y ? start.y - end.y : 0;
  Needed[2] = start.x > end.x ? start.x - end.x : 0;
  Needed[3] = end.y > start.y ? end.y - start.y : 0;
  string line;
  cin >> line;
  length = line.size();
  for (int i = 0; i < length; ++i) {
    if (line[i] == 'E') ++exsist[0];
    if (line[i] == 'S') ++exsist[1];
    if (line[i] == 'W') ++exsist[2];
    if (line[i] == 'N') ++exsist[3];
  }
  bool soluation = true;
  for (int i = 0; i < 4; i++) {
    if (Needed[i] && Needed[i] > exsist[i]) {
      soluation = false;
      break;
    }
  }
  if (soluation) {
    int time = t;
    for (int i = 0; i < length; i++) {
      if (done()) {
        time = i;
        break;
      }
      if (Needed[0] && line[i] == 'E') --Needed[0];
      if (Needed[1] && line[i] == 'S') --Needed[1];
      if (Needed[2] && line[i] == 'W') --Needed[2];
      if (Needed[3] && line[i] == 'N') --Needed[3];
    }
    cout << time << endl;
  } else
    cout << -1 << endl;
  return 0;
}
