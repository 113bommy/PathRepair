#include <bits/stdc++.h>
using namespace std;
const int mxn = 1.e5;
int place[mxn];
int main() {
  int n;
  cin >> n;
  int nazdik, dur;
  for (int(i) = (0); (i) < (n); (i)++) cin >> place[i];
  for (int(i) = (0); (i) < (n); (i)++) {
    if (i == 0) {
      nazdik = abs(place[i + 1] - place[i]);
      dur = abs(place[n - 1] - place[i]);
    } else if (i == n - 1) {
      nazdik = abs(place[i] - place[i - 1]);
      dur = abs(place[i] - place[0]);
    } else {
      nazdik = min(abs(place[i + 1] - place[i]), abs(place[i] - place[i - 1]));
      dur = max(abs(place[i] - place[0]), abs(place[n - 1] - place[i]));
    }
    cout << nazdik << ' ' << dur << "\n";
  }
}
