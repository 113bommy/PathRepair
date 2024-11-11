#include <bits/stdc++.h>
using namespace std;
int arr[10], brr[10];
int a1[5], b1[5];
int main() {
  int n;
  cin >> n;
  vector<string> s[5], a, b;
  int i, j;
  int ar[101], br[101];
  for (i = 0; i < 10; i++) arr[i] = 0;
  for (i = 0; i < n; i++) {
    string p;
    cin >> p;
    a.push_back(p);
    if (p == "M") {
      arr[1]++;
      a1[1]++;
    } else if (p == "S") {
      arr[2]++;
      a1[1]++;
    } else if (p == "L") {
      arr[3]++;
      a1[1]++;
    } else if (p == "XS") {
      arr[4]++;
      a1[2]++;
    } else if (p == "XL") {
      arr[5]++;
      a1[2]++;
    } else if (p == "XXS") {
      arr[6]++;
      a1[3]++;
    } else if (p == "XXL") {
      arr[7]++;
      a1[3]++;
    } else if (p == "XXXS") {
      arr[8]++;
      a1[4]++;
    } else if (p == "XXXL") {
      arr[9]++;
      a1[4]++;
    }
  }
  for (i = 0; i < n; i++) {
    string p;
    cin >> p;
    b.push_back(p);
    if (p == "M") {
      brr[1]++;
      b1[1]++;
    } else if (p == "S") {
      brr[2]++;
      b1[1]++;
    } else if (p == "L") {
      brr[3]++;
      b1[1]++;
    } else if (p == "XS") {
      brr[4]++;
      b1[2]++;
    } else if (p == "XL") {
      brr[5]++;
      b1[2]++;
    } else if (p == "XXS") {
      brr[6]++;
      b1[3]++;
    } else if (p == "XXL") {
      brr[7]++;
      b1[3]++;
    } else if (p == "XXXS") {
      brr[8]++;
      b1[4]++;
    } else if (p == "XXXL") {
      brr[9]++;
      b1[4]++;
    }
  }
  int ans = 0;
  for (i = 1; i < 10; i++) {
    if (brr[i] > 0 && arr[i] == 0) {
      ans += abs(brr[i] - arr[i]);
    }
  }
  cout << ans << '\n';
  return 0;
}
