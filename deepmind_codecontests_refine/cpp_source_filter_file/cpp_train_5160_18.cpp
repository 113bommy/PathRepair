#include <bits/stdc++.h>
using namespace std;
const int MAX_BUF_SIZE = 16384;
char BUFOR[MAX_BUF_SIZE];
int BUF_SIZE, BUF_POS;
char ZZZ;
const int MXN = 1000010;
const int C = 262144;
const int INF = 1000000001;
int n;
int a[MXN];
void test() {
  cin >> n;
  int x, y, z;
  cout << "? 1 2\n";
  cin >> x;
  cout << "? 2 3\n";
  cin >> y;
  cout << "? 3 1\n";
  cin >> z;
  a[1] = (x + z - 2 * y) / 2;
  a[2] = x - a[1];
  a[3] = z - a[1];
  for (int i = (4); i <= (n); i++) {
    cout << "? 1 " << i << "\n";
    int y;
    cin >> y;
    a[i] = y - a[1];
  }
  cout << "! ";
  for (int i = (1); i <= (n); i++) cout << a[i] << " ";
  cout << "\n";
}
int main() {
  int te = 1;
  while (te--) test();
  return 0;
}
