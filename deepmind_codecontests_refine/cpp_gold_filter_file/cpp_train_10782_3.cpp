#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cerr.tie(nullptr);
  int a, b, c;
  cin >> a >> b >> c;
  int m;
  cin >> m;
  vector<long long> usb;
  vector<long long> pc;
  long long tem;
  string s;
  for (int i = 0; i < m; i++) {
    cin >> tem >> s;
    if (s == "USB") {
      usb.push_back(tem);
    } else {
      pc.push_back(tem);
    }
  }
  sort(usb.begin(), usb.end());
  sort(pc.begin(), pc.end());
  usb.push_back(-1);
  pc.push_back(-1);
  unsigned long long res = 0;
  int num = 0;
  int index = 0;
  for (int i = 0; i < a; i++) {
    if (usb[index] == -1) {
      break;
    } else {
      res += usb[index];
      index++;
    }
    num++;
  }
  int index1 = 0;
  for (int i = 0; i < b; i++) {
    if (pc[index1] == -1) {
      break;
    } else {
      res += pc[index1];
      index1++;
    }
    num++;
  }
  for (int i = 0; i < c; i++) {
    if (pc[index1] == -1 && usb[index] == -1) {
      break;
    } else if (pc[index1] == -1) {
      res += usb[index];
      index++;
    } else if (usb[index] == -1) {
      res += pc[index1];
      index1++;
    } else {
      if (usb[index] <= pc[index1]) {
        res += usb[index];
        index++;
      } else {
        res += pc[index1];
        index1++;
      }
    }
    num++;
  }
  cout << num << " " << res << endl;
  return 0;
}
