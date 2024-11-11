#include <bits/stdc++.h>
using namespace std;
int getZeros(string str) {
  bool hasOne = false;
  int count = 0;
  for (int i = 0; i < str.size(); i++) {
    if (str[i] == '1') {
      if (hasOne) return -1;
      hasOne = true;
    } else if (str[i] != '0') {
      return -1;
    } else {
      count++;
    }
  }
  return count;
}
int main() {
  int N;
  cin >> N;
  int count = 0;
  string starter = "1";
  for (int i = 0; i < N; i++) {
    string a;
    cin >> a;
    if (a == "1") continue;
    if (a == "0") {
      cout << 0 << endl;
      return 0;
    }
    int zeros = getZeros(a);
    if (zeros == -1)
      starter = a;
    else {
      count += zeros;
    }
  }
  for (int i = 0; i < count; i++) {
    starter.push_back('0');
  }
  cout << starter << endl;
  return 0;
}
