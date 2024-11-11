#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<pair<int, int> > vect;
  int i, x, j, y, a, b, c = 0, d = 0, tc = 0, p = 0, q = 0;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    vect.push_back(make_pair(x, y));
  }
  for (int i = 0; i < n; i++) {
    a = vect[i].first;
    b = vect[i].second;
    c = 0;
    d = 0;
    for (j = 0; j < n; j++) {
      if (vect[j].first == a && (vect[j].second < b || vect[j].second > b)) {
        if (vect[j].second < b) {
          c++;
          if (c >= 1 && d >= 1) {
            break;
          }
        } else if (vect[j].second > b) {
          d++;
          if (c >= 1 && d >= 1) {
            break;
          }
        } else {
          continue;
        }
      }
    }
    p = 0;
    q = 0;
    for (j = 0; j < n; j++) {
      if (vect[j].second == b && (vect[j].first < a || vect[j].second > a)) {
        if (vect[j].first < a) {
          p++;
          if (p >= 1 && q >= 1 && c >= 1 && d >= 1) {
            tc++;
            break;
          }
        } else if (vect[j].first > a) {
          q++;
          if (p >= 1 && q >= 1 && c >= 1 && d >= 1) {
            tc++;
            break;
          }
        } else {
          continue;
        }
      }
    }
  }
  cout << tc << endl;
  return 0;
}
