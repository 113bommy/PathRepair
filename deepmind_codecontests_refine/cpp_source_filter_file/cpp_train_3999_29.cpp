#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int main() {
  cin >> n;
  int count = 0;
  char back;
  char front;
  cin >> s;
  back = s[1];
  front = s[0];
  for (int i = 0; i < n - 1; i++) {
    cin >> s;
    char newfront = s[0];
    char newback = s[1];
    if (back == newfront) ++count;
    back = newback;
    front = newfront;
  }
  cout << count;
}
