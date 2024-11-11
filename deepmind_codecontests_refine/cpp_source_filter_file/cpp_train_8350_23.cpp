#include <bits/stdc++.h>
using namespace std;
struct Time {
  int hour;
  int mins;
  int secs;
};
Time findTimeDifference(Time t1, Time t2) {
  Time diff;
  if (t2.secs > t1.secs) {
    --t1.mins;
    t1.secs += 60;
  }
  diff.secs = t1.secs - t2.secs;
  if (t2.mins > t1.mins) {
    --t1.hour;
    t1.mins += 60;
  }
  diff.mins = t1.mins - t2.mins;
  diff.hour = t1.hour - t2.hour;
  return diff;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    Time t1, t2, diff;
    cin >> t1.hour >> t1.mins;
    t1.secs = 0;
    t2.hour = 0;
    t2.mins = 0;
    t2.secs = 0;
    diff = findTimeDifference(t1, t2);
    cout << diff.hour * 60 + diff.mins << "\n";
  }
  return 0;
}
