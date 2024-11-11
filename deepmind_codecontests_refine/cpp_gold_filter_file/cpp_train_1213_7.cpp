#include <bits/stdc++.h>
using namespace std;
char f, g;
string s, p;
map<int, int> mi;
map<string, int> ms;
vector<int> v, va;
double arr[100005];
int brr[100005], crr[105];
int main() {
  double a, b, c, m, l, r, j, k, x, y, z = 0;
  int n, i, aa, t = 0;
  cin >> n >> a >> b;
  x = 0;
  for (i = 1; i <= n; i++) {
    cin >> brr[i];
    arr[i] = brr[i];
    x += brr[i];
  }
  k = x;
  sort(brr + 2, brr + n + 1);
  if ((arr[1] * a) / k >= b) {
    cout << 0 << endl;
  } else {
    i = n;
    while (true) {
      t++;
      k -= brr[i];
      i--;
      if ((arr[1] * a) / k >= b) {
        cout << t << endl;
        return 0;
      }
    }
  }
  return 0;
}
