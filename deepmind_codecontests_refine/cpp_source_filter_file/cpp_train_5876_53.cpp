#include <bits/stdc++.h>
using namespace std;
int main() {
  string s1;
  string s2;
  string temp;
  cin >> s1 >> s2;
  for (int i = s2.length() - 1; i >= 0; i--) {
    temp = temp + s2[i];
  }
  if (s1 == temp) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
