#include <bits/stdc++.h>
using namespace std;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
const int dxK[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dyK[] = {0, 1, 1, 1, 0, -1, -1, -1};
long long n;
long long resp, resp1, resp2;
int main(int argc, char const *argv[]) {
  cout.flush();
  int A = 0, B = 0;
  cout << "? " << 0 << " " << 0 << endl;
  cin >> resp;
  int greater = 0;
  if (resp == 1)
    greater = 1;
  else
    greater = 2;
  for (int i = 29; i >= 0; --i) {
    int k = 1 << i;
    cout << "? " << (A ^ k) << " " << B << endl;
    cin >> resp1;
    cout << A << " " << (B ^ k) << endl;
    cin >> resp2;
    if (resp2 != resp1) {
      if (resp2 == 1) {
        A ^= (1 << i);
        B ^= (1 << i);
      }
    } else {
      if (greater == 1)
        A ^= (1 << i);
      else
        B ^= (1 << i);
      if (resp1 == 1)
        greater = 1;
      else
        greater = 2;
    }
  }
  cout << "! " << A << " " << B << endl;
  return 0;
}
