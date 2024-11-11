#include <bits/stdc++.h>
using namespace std;
const int E = 1e5 + 5;
int A[E];
int a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, q, r, x, y, z;
string s, t, u, w;
bool ok, fine, pass;
vector<int> v;
queue<int> p;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> a >> s;
  for (int q = 0; q < a; q++) {
    cin >> t;
    if (t.find(s) == 0) {
      h++;
    }
  }
  if (h % 2 == 0) {
    cout << "home";
  } else {
    cout << "contest";
  }
}
