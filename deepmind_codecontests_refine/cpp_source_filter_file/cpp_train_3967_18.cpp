#include <bits/stdc++.h>
using namespace std;
bool compare(long long int x, long long int y) { return x > y; }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t = 1;
  while (t--) {
    long long int i = 0, j = 0, k = 0, l = 0, z = 0;
    long long int n, m = 0;
    cin >> n >> m;
    string a = "", b = "";
    string c = "4", d = "5";
    {
      z = n;
      while (z > 0) {
        if (z >= 5) {
          a = a + c;
          b = b + d;
          swap(c, d);
          z = z - 5;
        } else {
          a = a + "5";
          b = b + "5";
          z = 0;
        }
      }
      cout << a << endl;
      cout << b << endl;
    }
  }
}
