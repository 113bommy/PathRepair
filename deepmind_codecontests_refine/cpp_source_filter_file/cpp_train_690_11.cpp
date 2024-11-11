#include <bits/stdc++.h>
using namespace std;
struct bal {
  long long r, id;
};
bool cmp(bal a, bal b) { return a.r < b.r; }
int main() {
  long long n, a, b;
  cin >> n >> a >> b;
  bal s[n];
  for (int i = 0; i < n; i++) {
    cin >> s[i].r;
    s[i].id = i + 1;
  }
  sort(s, s + n, cmp);
  int an1 = -1, an2 = -1;
  for (int i = n - 1; i >= 0; i--) {
    int rq = ceil((double)a / s[i].r);
    if (rq <= n - i) {
      an1 = i;
      break;
    }
  }
  if (an1 != -1) {
    for (int i = an1 - 1; i >= 0; i--) {
      int rq = ceil((double)b / s[i].r);
      if (rq == an1 - i) {
        an2 = i;
        break;
      }
    }
  }
  int an3 = -1, an4 = -1;
  for (int i = n - 1; i >= 0; i--) {
    int rq = ceil((double)b / s[i].r);
    if (rq <= n - i) {
      an3 = i;
      break;
    }
  }
  if (an3 != -1) {
    for (int i = an1 - 1; i >= 0; i--) {
      int rq = ceil((double)a / s[i].r);
      if (rq == an3 - i) {
        an4 = i;
        break;
      }
    }
  }
  if ((an1 == -1 || an2 == -1) && (an3 == -1 || an4 == -1))
    cout << "NO\n";
  else {
    cout << "YES\n";
    if (an3 != -1 && an4 != -1) {
      cout << an3 - an4 << " " << n - an3 << "\n";
      for (int i = an4; i < an3; i++) cout << s[i].id << " ";
      cout << "\n";
      for (int i = an3; i < n; i++) cout << s[i].id << " ";
    } else {
      cout << n - an1 << " " << an1 - an2 << "\n";
      for (int i = an1; i < n; i++) cout << s[i].id << " ";
      cout << "\n";
      for (int i = an2; i < an1; i++) cout << s[i].id << " ";
    }
  }
  return 0;
}
