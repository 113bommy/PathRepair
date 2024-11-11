#include <bits/stdc++.h>
using namespace std;

int e[4];

int main() {
  cin >> e[0] >> e[1] >> e[2] >> e[3];
  sort(e,e+4)
  if(e[0] == e[1] && e[2] == e[3]) {
    cout << "yes" << endl;
  }else {
    cout << "no" << endl;
  }
}