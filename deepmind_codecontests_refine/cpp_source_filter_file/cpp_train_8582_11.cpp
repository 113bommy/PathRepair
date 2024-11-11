#include <bits/stdc++.h>
using namespace std;
int main() {
  string str[8] = {"vaporeon", "jolteon", "flareon", "espeon",
                   "umbreon",  "leafeon", "glaceon", "sylveon"};
  int n;
  int value[8];
  string sample;
  while (cin >> n) {
    cin >> sample;
    if (n == 8)
      cout << str[0] << endl;
    else if (n == 6)
      cout << str[3] << endl;
    else {
      memset(value, 0, sizeof(value));
      int i;
      switch (sample[0]) {
        case 'j':
          value[1]++;
          break;
        case 'f':
          value[2]++;
          break;
        case 'u':
          value[4]++;
          break;
        case 'l':
          value[5]++;
          break;
        case 'g':
          value[6]++;
          break;
        case 's':
          value[7]++;
          break;
      }
      switch (sample[1]) {
        case 'o':
          value[1]++;
          break;
        case 'l':
          value[2]++;
          value[6]++;
          break;
        case 'm':
          value[4]++;
          break;
        case 'e':
          value[5]++;
          break;
        case 'y':
          value[7]++;
          break;
      }
      switch (sample[2]) {
        case 'l':
          value[1]++;
          value[7]++;
          break;
        case 'a':
          value[2]++;
          value[5]++;
          value[6]++;
          break;
        case 'b':
          value[4]++;
          break;
      }
      switch (sample[3]) {
        case 't':
          value[1]++;
          break;
        case 'r':
          value[2]++;
          value[4]++;
          break;
        case 'f':
          value[5]++;
          break;
        case 'c':
          value[6]++;
          break;
        case 'v':
          value[7]++;
          break;
      }
      switch (sample[4]) {
        case 'e':
          value[1]++;
          value[2]++;
          value[4]++;
          value[5]++;
          value[6]++;
          value[7]++;
          break;
      }
      switch (sample[5]) {
        case 'o':
          value[1]++;
          value[2]++;
          value[4]++;
          value[5]++;
          value[6]++;
          value[7]++;
          break;
      }
      switch (sample[6]) {
        case 'n':
          value[1]++;
          value[2]++;
          value[4]++;
          value[5]++;
          value[6]++;
          value[7]++;
          break;
      }
      int res = 0;
      int ans = 1;
      for (i = 0; i < 7; ++i) {
        if (res < value[i]) {
          res = value[i];
          ans = i;
        }
      }
      cout << str[ans] << endl;
    }
  }
}
