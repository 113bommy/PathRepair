#include <bits/stdc++.h>
using namespace std;
int n;
int t[5], c[5];
bool bl;
void out1() {
  cout << t[0] << " " << t[1] << endl;
  cout << t[2] << " " << t[3] << endl;
  cout << t[0] << " " << t[3] << endl;
  cout << t[1] << " " << t[2] << endl;
  cout << t[0] << " " << t[4] << endl;
  cout << t[1] << " " << t[4] << endl;
  cout << t[0] << " " << t[2] << endl;
  cout << t[1] << " " << t[3] << endl;
  cout << t[3] << " " << t[4] << endl;
  cout << t[2] << " " << t[4] << endl;
}
void out2() {
  cout << t[0] << " " << t[1] << endl;
  cout << t[2] << " " << t[3] << endl;
  cout << t[0] << " " << t[3] << endl;
  cout << t[1] << " " << t[2] << endl;
  cout << t[0] << " " << t[2] << endl;
  cout << t[1] << " " << t[3] << endl;
}
void out3() {
  cout << t[0] << " " << c[0] << endl;
  cout << t[1] << " " << c[1] << endl;
  cout << t[0] << " " << c[1] << endl;
  cout << t[1] << " " << c[0] << endl;
  cout << t[0] << " " << c[2] << endl;
  cout << t[1] << " " << c[3] << endl;
  cout << t[0] << " " << c[3] << endl;
  cout << t[1] << " " << c[2] << endl;
  cout << t[2] << " " << c[0] << endl;
  cout << t[3] << " " << c[1] << endl;
  cout << t[2] << " " << c[1] << endl;
  cout << t[3] << " " << c[0] << endl;
  cout << t[2] << " " << c[2] << endl;
  cout << t[3] << " " << c[3] << endl;
  cout << t[2] << " " << c[3] << endl;
  cout << t[3] << " " << c[2] << endl;
}
int main() {
  cin >> n;
  if (n % 4 > 1) {
    cout << "No";
    return 0;
  }
  cout << "Yes" << endl;
  bl = n & 3;
  if (bl) t[4] = n--;
  for (int i = 0; i < n; i += 4) {
    for (int j = 0; j < 4; j++) t[j] = i + j + 1;
    if (bl)
      out1();
    else
      out2();
  }
  for (int i = 0; i < n; i += 4)
    for (int j = i + 4; j < n; j += 4) {
      for (int k = 0; k < 4; k++) t[k] = i + k + 1;
      for (int k = 0; k < 4; k++) c[k] = j + k + 1;
      out3();
    }
  return 0;
}
