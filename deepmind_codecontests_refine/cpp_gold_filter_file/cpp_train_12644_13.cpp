#include <bits/stdc++.h>
using namespace std;
struct dot {
  string f, s;
};
bool cmp(dot x, dot y) {}
int main() {
  int i, j, k, n;
  int p[100010];
  dot A[100010];
  cin >> n;
  for (int(i) = int(1); i <= int(n); i++) {
    cin >> A[i].f >> A[i].s;
  }
  string las = "";
  for (int(i) = int(1); i <= int(n); i++) {
    cin >> p[i];
  }
  bool OK = true;
  las = min(A[p[1]].f, A[p[1]].s);
  for (int(i) = int(2); i <= int(n); i++) {
    if (min(A[p[i]].f, A[p[i]].s) > las)
      las = min(A[p[i]].f, A[p[i]].s);
    else if (max(A[p[i]].f, A[p[i]].s) > las) {
      las = max(A[p[i]].f, A[p[i]].s);
    } else {
      OK = false;
      break;
    }
  }
  if (OK)
    cout << "YES\n";
  else
    cout << "NO" << endl;
}
