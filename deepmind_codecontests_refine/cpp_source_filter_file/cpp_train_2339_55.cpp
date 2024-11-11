#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(20);
  string a[3];
  unordered_map<string, int> mp;
  for (int i = 0; i < 3; i++) {
    cin >> a[i];
    mp[a[i]]++;
  }
  if (mp["rock"] == 1 && mp["scissors"] == 1 && mp["paper"] == 1)
    cout << "?";
  else if (mp["rock"] == 3 || mp["scissors"] == 3 || mp["paper"] == 3)
    cout << "?";
  else if (mp["rock"] == 2 && mp["paper"] == 1) {
    for (int i = 0; i < 3; i++) {
      if (a[i] == "paper") {
        if (i == 0)
          cout << "F";
        else if (i == 1)
          cout << "M";
        else
          cout << "S";
      }
    }
  } else if (mp["scissors"] == 1 && mp["paper"] == 2) {
    for (int i = 0; i < 3; i++) {
      if (a[i] == "scissor") {
        if (i == 0)
          cout << "F";
        else if (i == 1)
          cout << "M";
        else
          cout << "S";
      }
    }
  } else if (mp["rock"] == 1 && mp["scissors"] == 2) {
    for (int i = 0; i < 3; i++) {
      if (a[i] == "rock") {
        if (i == 0)
          cout << "F";
        else if (i == 1)
          cout << "M";
        else
          cout << "S";
      }
    }
  } else
    cout << "?";
}
