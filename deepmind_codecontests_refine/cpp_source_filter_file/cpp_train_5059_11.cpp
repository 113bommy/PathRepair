#include <bits/stdc++.h>
using namespace std;
long long last_i(int new_i) {
  long long num;
  num = (new_i - 42);
  if (num < 0) {
    num = 475 + num;
  }
  num = (num * 84934656) % 475;
  return num;
}
int main() {
  int placement, highscore, nid_tis_score;
  cin >> placement >> highscore >> nid_tis_score;
  placement -= 26;
  int num[100];
  num[1] = placement;
  for (int n = 2; n <= 25; n++) {
    num[n] = last_i(num[n - 1]);
  }
  int temp = nid_tis_score / 50, mini = 2147483647;
  bool stop = false;
  for (int n = 1; n <= 25 && !stop; n++) {
    int i = num[n];
    if (i < temp) {
      i += ((temp - i) / 475) * 475;
      if (i < temp) {
        i += 475;
      }
    }
    bool p475 = false, go = true;
    int nid;
    if (i == temp) {
      if (highscore % 50 >= nid_tis_score % 50) {
        nid += 50 * i + highscore % 50;
        go = false;
      } else {
        p475 = true;
      }
    } else if (go) {
      if (p475) {
        i += 475;
      }
      nid = 50 * i + highscore % 50;
    }
    mini = min(mini, nid);
    if (mini <= highscore) {
      stop = true;
    }
  }
  if (mini <= highscore) {
    cout << 0;
  } else {
    int change = mini - highscore;
    if (change % 100 != 0) {
      change += 50;
    }
    cout << (change / 100);
  }
  return 0;
}
