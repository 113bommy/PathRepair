#include <bits/stdc++.h>
using namespace std;
int main() {
  string time;
  cin >> time;
  int a = time[0] - '0';
  int b = time[1] - '0';
  int c = time[3] - '0';
  int d = time[4] - '0';
  int hour = a * 10 + b;
  int minute = c * 10 + d;
  int ans;
  if (hour >= 0 && hour <= 4) {
    if (minute <= hour * 10) {
      ans = hour * 10 - minute;
    } else if (minute > hour * 10) {
      ans = 60 - minute + (hour + 1) * 10;
    }
  } else if (hour == 5) {
    if (minute <= 50) {
      ans = 50 - minute;
    } else if (minute > 50) {
      ans = 60 - minute + 241;
    }
  } else if (hour >= 6, hour <= 9) {
    ans = 60 - minute + (10 - hour - 1) * 60 + 1;
  } else if (hour == 10) {
    if (minute <= 1) {
      ans = 1 - minute;
    }
    if (minute > 1) {
      ans = 60 - minute + 11;
    }
  } else if (hour == 11) {
    if (minute <= 11) {
      ans = 11 - minute;
    } else if (minute > 11) {
      ans = 60 - minute + 21;
    }
  } else if (hour == 12) {
    if (minute <= 21) {
      ans = 21 - minute;
    } else if (minute > 21) {
      ans = 60 - minute + 31;
    }
  } else if (hour == 13) {
    if (minute <= 31) {
      ans = 31 - minute;
    } else if (minute > 31) {
      ans = 60 - minute + 41;
    }
  } else if (hour == 14) {
    if (minute <= 41) {
      ans = 41 - minute;
    } else if (minute > 41) {
      ans = 60 - minute + 51;
    }
  } else if (hour == 15) {
    if (minute <= 51) {
      ans = 51 - minute;
    } else if (minute > 51) {
      ans = 60 - minute + 242;
    }
  } else if (hour >= 16 && hour <= 19) {
    ans = 60 - minute + 60 * (20 - hour - 1) + 2;
  } else if (hour == 20) {
    if (minute <= 2) {
      ans = 2 - minute;
    } else if (minute > 2) {
      ans = 60 - minute + 12;
    }
  } else if (hour == 21) {
    if (minute <= 12) {
      ans = 12 - minute;
    } else if (minute > 12) {
      ans = 60 - minute + 22;
    }
  } else if (hour == 22) {
    if (minute <= 22) {
      ans = 22 - minute;
    } else if (minute > 22) {
      ans = 60 - minute + 32;
    }
  } else if (hour == 23) {
    if (minute <= 32) {
      ans = 32 - minute;
    } else if (minute > 32) {
      ans = 60 - minute;
    }
  }
  cout << ans << endl;
}
