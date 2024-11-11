#include <bits/stdc++.h>
using namespace std;
bool check[6];
int main() {
  string name[6], color[6];
  name[0] = "Power";
  name[1] = "Time";
  name[2] = "Space";
  name[3] = "Soul";
  name[4] = "Reality";
  name[5] = "Mind";
  color[0] = "purple";
  color[1] = "green";
  color[2] = "blue";
  color[3] = "orange";
  color[4] = "red";
  color[5] = "yellow";
  int n;
  cin >> n;
  string chk[n];
  for (int i = 0; i < n; i++) {
    cin >> chk[i];
  }
  for (int i = 0; i < n; i++) {
    if (chk[i] == "purple") check[0] = true;
    if (chk[i] == "green") check[1] = true;
    if (chk[i] == "blue") check[2] = true;
    if (chk[i] == "orange") check[3] = true;
    if (chk[i] == "red") check[0] = true;
    if (chk[i] == "yellow") check[0] = true;
  }
  cout << 6 - n << endl;
  for (int i = 0; i < 6; i++) {
    if (check[i] == false) cout << name[i] << endl;
  }
}
