#include <bits/stdc++.h>
using namespace std;
int hour[10];
int mini[10];
int main() {
  memset(hour, 0, sizeof(hour));
  memset(mini, 0, sizeof(mini));
  string s;
  cin >> s;
  string s1 = "";
  string s2 = "";
  int i = 0;
  for (i = 0; i < s.size(); i++) {
    if (s[i] != ':') {
      s1 += s[i];
    } else {
      i++;
      break;
    }
  }
  for (i = i; i < s.size(); i++) {
    s2 += s[i];
  }
  while (s1.size() < 5) {
    string tmps = '0' + s1;
    s1 = tmps;
  }
  while (s2.size() < 5) {
    string tmps = '0' + s2;
    s2 = tmps;
  }
  int count = 4;
  for (int i = 0; i < s1.size(); i++) {
    if (int(s1[i]) >= 48 && int(s1[i]) <= 57) {
      hour[count] = int(s1[i]) - 48;
    } else
      hour[count] = int(s1[i]) - 55;
    count--;
  }
  count = 4;
  for (int i = 0; i < s2.size(); i++) {
    if (int(s2[i]) >= 48 && int(s2[i]) <= 57) {
      mini[count] = int(s2[i]) - 48;
    } else
      mini[count] = int(s2[i]) - 55;
    count--;
  }
  if (hour[0] < 24 && hour[1] == 0 && hour[2] == 0 && hour[3] == 0 &&
      hour[4] == 0 && mini[0] < 60 && mini[1] == 0 && mini[2] == 0 &&
      mini[3] == 0 && mini[4] == 0) {
    cout << "-1";
    return 0;
  }
  int max = 0;
  for (int i = 0; i < 5; i++) {
    if (hour[i] > max) max = hour[i];
    if (mini[i] > max) max = mini[i];
  }
  int start = max + 1;
  while (1) {
    int sum1 = 0;
    int sum2 = 0;
    for (int i = 0; i < 5; i++) {
      sum1 += hour[i] * pow(start, i);
      sum2 += mini[i] * pow(start, i);
    }
    if (sum1 > 23 || sum2 > 59) {
      if (start == max + 1) cout << "0";
      break;
    } else {
      cout << start << " ";
      start++;
    }
  }
  return 0;
}
