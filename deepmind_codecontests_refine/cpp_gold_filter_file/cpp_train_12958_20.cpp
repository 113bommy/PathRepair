#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int addxy[] = {-1000000, 1000000};
  int subxy[] = {-1000000, 1000000};
  int temp[2], n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 2; j++) cin >> temp[j];
    addxy[0] = (addxy[0] > temp[0] + temp[1] ? addxy[0] : temp[0] + temp[1]);
    addxy[1] = (addxy[1] < temp[0] + temp[1] ? addxy[1] : temp[0] + temp[1]);
    subxy[0] = (subxy[0] > temp[0] - temp[1] ? subxy[0] : temp[0] - temp[1]);
    subxy[1] = (subxy[1] < temp[0] - temp[1] ? subxy[1] : temp[0] - temp[1]);
  }
  cout << addxy[0] - addxy[1] + subxy[0] - subxy[1] + 4 << endl;
  return 0;
}
