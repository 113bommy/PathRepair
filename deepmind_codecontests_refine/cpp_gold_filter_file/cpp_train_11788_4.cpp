#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  while (n--) {
    string num;
    cin >> num;
    int count = 0;
    for (int i = num.find('1'); i < num.find_last_of('1'); i++) {
      if (num[i] == '0') {
        count++;
      }
    }
    cout << count << '\n';
  }
}
