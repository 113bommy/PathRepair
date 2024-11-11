#include <bits/stdc++.h>
using namespace std;
string s[1005];
int main() {
  int arr[5];
  for (int i = 0; i < 5; i++) cin >> arr[i];
  int k;
  cin >> k;
  string ss;
  int f = -1;
  for (int i = 1; i <= k; i++) {
    f++;
    cin >> ss;
    if (ss == "S") {
      if (arr[0] != 0) {
        arr[0]--;
        s[f] = "S";
        continue;
      }
      if (arr[0] == 0 && arr[1] != 0) {
        arr[1]--;
        s[f] = "M";
        continue;
      }
      if (arr[0] == 0 && arr[2] != 0) {
        arr[2]--;
        s[f] = "L";
        continue;
      }
      if (arr[0] == 0 && arr[3] != 0) {
        arr[3]--;
        s[f] = "XL";
        continue;
      }
      if (arr[0] == 0 && arr[4] != 0) {
        arr[4]--;
        s[f] = "XXL";
        continue;
      }
    }
    if (ss == "M") {
      if (arr[1] != 0) {
        arr[1]--;
        s[f] = "M";
        continue;
      }
      if (arr[1] == 0 && arr[2] != 0) {
        arr[2]--;
        s[f] = "L";
        continue;
      }
      if (arr[1] == 0 && arr[0] != 0) {
        arr[0]--;
        s[f] = "S";
        continue;
      }
      if (arr[1] == 0 && arr[3] != 0) {
        arr[3]--;
        s[f] = "XL";
        continue;
      }
      if (arr[1] == 0 && arr[4] != 0) {
        arr[4]--;
        s[f] = "XXL";
        continue;
      }
    }
    if (ss == "L") {
      if (arr[2] != 0) {
        arr[2]--;
        s[f] = "L";
        continue;
      }
      if (arr[2] == 0 && arr[3] != 0) {
        arr[3]--;
        s[f] = "XL";
        continue;
      }
      if (arr[2] == 0 && arr[1] != 0) {
        arr[1]--;
        s[f] = "M";
        continue;
      }
      if (arr[2] == 0 && arr[4] != 0) {
        arr[4]--;
        s[f] = "XXL";
        continue;
      }
      if (arr[2] == 0 && arr[0] != 0) {
        arr[0]--;
        s[f] = "S";
        continue;
      }
    }
    if (ss == "XL") {
      if (arr[3] != 0) {
        arr[3]--;
        s[f] = "XL";
        continue;
      }
      if (arr[3] == 0 && arr[4] != 0) {
        arr[4]--;
        s[f] = "XXL";
        continue;
      }
      if (arr[3] == 0 && arr[2] != 0) {
        arr[2]--;
        s[f] = "L";
        continue;
      }
      if (arr[3] == 0 && arr[1] != 0) {
        arr[1]--;
        s[f] = "M";
        continue;
      }
      if (arr[3] == 0 && arr[0] != 0) {
        arr[0]--;
        s[f] = "S";
        continue;
      }
    }
    if (ss == "XXL") {
      if (arr[4] != 0) {
        arr[4]--;
        s[f] = "XXL";
        continue;
      }
      if (arr[4] == 0 && arr[3] != 0) {
        arr[3]--;
        s[f] = "XL";
        continue;
      }
      if (arr[4] == 0 && arr[2] != 0) {
        arr[2]--;
        s[f] = "L";
        continue;
      }
      if (arr[4] == 0 && arr[1] != 0) {
        arr[3]--;
        s[f] = "M";
        continue;
      }
      if (arr[4] == 0 && arr[0] != 0) {
        arr[0]--;
        s[f] = "S";
        continue;
      }
    }
  }
  for (int i = 0; i < k; i++) cout << s[i] << endl;
  return 0;
}
