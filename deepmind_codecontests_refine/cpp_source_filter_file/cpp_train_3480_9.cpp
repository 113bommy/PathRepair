#include <bits/stdc++.h>
using namespace std;
int main() {
  int maxSections, nuts, divis, nut2sec, boxes = 0;
  cin >> maxSections >> nuts >> divis >> nut2sec;
  while (nuts >= 0) {
    boxes++;
    nuts -= (min(maxSections, divis + 1)) * nut2sec;
    divis -= min(maxSections, divis + 1) - 1;
  }
  cout << boxes << endl;
  return 0;
}
