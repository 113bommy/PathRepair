#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int n, mins;
  cin >> n >> mins;
  int songs[n];
  for (int i = 0; i < n; i++) {
    cin >> songs[i];
  }
  int njokes = 0;
  for (int i = 0; i <= n - 2; i++) {
    if (mins <= 0) {
      cout << "-1" << endl;
      return 0;
    }
    mins -= songs[i];
    mins -= 10;
    njokes += 2;
  }
  mins -= songs[n - 1];
  if (mins <= 0) {
    cout << "-1" << endl;
    return 0;
  }
  njokes += mins / 5;
  cout << njokes << endl;
  return 0;
}
