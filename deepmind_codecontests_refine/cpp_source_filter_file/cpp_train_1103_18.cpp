#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  string str;
  cin >> str;
  long long sum = 0;
  for (int i = 0; i < str.length(); i++) {
    int x = str[i] - '0';
    sum += x;
  }
  if (sum > n) {
    cout << "0" << endl;
  } else {
    sort(str.begin(), str.end());
    int count1 = 0;
    for (int i = 0; i < str.length(); i++) {
      int x = str[i] - '0';
      int y = 9 - x;
      sum += y;
      count1++;
      if (sum >= n) {
        break;
      }
    }
    cout << count1 << endl;
  }
}
