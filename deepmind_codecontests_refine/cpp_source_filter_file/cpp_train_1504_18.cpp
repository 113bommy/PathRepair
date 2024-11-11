#include <bits/stdc++.h>
using namespace std;
struct guess {
  bool greater;
  bool include_equal;
  int val;
  bool yes;
};
int main() {
  int n;
  cin >> n;
  vector<guess> guesses;
  for (int i = 0; i < n; i++) {
    string stmp;
    int vtmp;
    char atmp;
    cin >> stmp >> vtmp >> atmp;
    guess tmp;
    if (stmp[0] == '>')
      tmp.greater = true;
    else
      tmp.greater = false;
    if (stmp.length() > 1)
      tmp.include_equal = true;
    else
      tmp.include_equal = false;
    if (atmp == 'Y')
      tmp.yes = true;
    else
      tmp.yes = false;
    tmp.val = vtmp;
    guesses.push_back(tmp);
  }
  const int MAX = 1000000000;
  const int MIN = -1000000000;
  int ymin = MIN;
  int ymax = MAX;
  for (int i = 0; i < n; i++) {
    guess current = guesses[i];
    if (current.yes) {
      if (current.greater) {
        if (current.include_equal) {
          ymin = max(ymin, current.val);
        } else {
          ymin = max(ymin, current.val + 1);
        }
      } else {
        if (current.include_equal) {
          ymax = min(ymax, current.val);
        } else {
          ymax = min(ymax, current.val - 1);
        }
      }
    } else {
      if (current.greater) {
        if (current.include_equal) {
          ymax = min(ymax, current.val - 1);
        } else {
          ymax = min(ymax, current.val);
        }
      } else {
        if (current.include_equal) {
          ymin = max(ymin, current.val + 1);
        } else {
          ymin = max(ymin, current.val);
        }
      }
    }
  }
  if (ymin > ymax)
    cout << "Impossible";
  else
    cout << ymin;
  return 0;
}
