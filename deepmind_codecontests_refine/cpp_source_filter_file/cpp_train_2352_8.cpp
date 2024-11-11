#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv) {
  int nh = 0, crush = 0, dol = 0, arr[100], step = 0, min = 101;
  cin >> nh >> crush >> dol;
  for (int i = 0; i < nh; i++) {
    cin >> arr[i];
    if (arr[i] == 0)
      continue;
    else if (dol > arr[i]) {
      step = abs((i + 1) - crush);
      if (min > step) min = step;
    }
  }
  cout << min * 10;
  return 0;
}
