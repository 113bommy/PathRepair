#include <bits/stdc++.h>
using namespace std;
int main(int argc, const char** argv) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  int in = 0;
  int t = 0;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    in -= a;
    in += b;
    if (in >= t) {
      t = in;
    }
  }
  cout << t << endl;
}
