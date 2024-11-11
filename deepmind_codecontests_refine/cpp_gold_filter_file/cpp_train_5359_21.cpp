#include <bits/stdc++.h>
using namespace std;
bool boys[101];
bool girls[101];
int main() {
  int b, g, hb, hg, i, j;
  cin >> b >> g;
  cin >> hb;
  for (i = 0; i < hb; i++) {
    cin >> j;
    boys[j] = true;
  }
  cin >> hg;
  for (i = 0; i < hg; i++) {
    cin >> j;
    girls[j] = true;
  }
  for (i = 0; i < 10005; i++) {
    if (boys[i % b] == true && girls[i % g] == false) girls[i % g] = true;
    if (girls[i % g] == true && boys[i % b] == false) boys[i % b] = true;
  }
  int flag = true;
  for (i = 0; i < b; i++) {
    if (boys[i] == false) {
      flag = false;
      break;
    }
  }
  for (i = 0; i < g; i++) {
    if (girls[i] == false) {
      flag = false;
      break;
    }
  }
  if (flag == true)
    cout << "Yes";
  else
    cout << "No";
  return 0;
}
