#include <bits/stdc++.h>
using namespace std;
int heavy[1001];
set<int> nose;
int arr[1001];
int main() {
  int me;
  cin >> me;
  int the = 1;
  while ((1 << the) < me) {
    the++;
  }
  fill(heavy, heavy + 1001, 1001 * 1001);
  for (int super = 1; super <= the; super++) {
    nose.clear();
    for (int very = 1; very <= me; very++) {
      if ((very % (1 << super)) <= (1 << (super - 1)) &&
          (very % (1 << super)) != 0) {
        nose.insert(very);
      }
    }
    cout << nose.size() << endl;
    for (int a : nose) {
      cout << a << ' ';
    }
    cout << endl;
    fflush(stdout);
    for (int kinda = 1; kinda <= me; kinda++) {
      cin >> arr[kinda];
      if (nose.find(kinda) == nose.end())
        heavy[kinda] = min(heavy[kinda], arr[kinda]);
    }
    nose.clear();
    for (int very = 1; very <= me; very++) {
      if ((very % (1 << super)) > (1 << (super - 1)) ||
          (very % (1 << super)) == 0) {
        nose.insert(very);
      }
    }
    cout << nose.size() << endl;
    for (int a : nose) {
      cout << a << ' ';
    }
    cout << endl;
    fflush(stdout);
    for (int kinda = 1; kinda <= me; kinda++) {
      cin >> arr[kinda];
      if (nose.find(kinda) == nose.end())
        heavy[kinda] = min(heavy[kinda], arr[kinda]);
    }
  }
  cout << -1 << endl;
  for (int super = 1; super <= me; super++) cout << heavy[super] << ' ';
  cout << endl;
  fflush(stdout);
}
