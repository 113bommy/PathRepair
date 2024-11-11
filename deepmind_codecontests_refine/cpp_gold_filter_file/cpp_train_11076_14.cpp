#include <bits/stdc++.h>
using namespace std;
int main() {
  string str;
  while (cin >> str) {
    long long sum = 0, heavy = 0;
    string temp;
    for (int i = 0; i < str.size(); i++) {
      temp = str.substr(i, 5);
      if (temp == "heavy")
        heavy++, i += 4;
      else if (temp == "metal")
        sum += heavy, i += 4;
    }
    cout << sum << endl;
  }
}
