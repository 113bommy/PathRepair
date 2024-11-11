#include <bits/stdc++.h>
using namespace std;
int di[4] = {1, 0, -1, 0};
int dj[4] = {0, 1, 0, -1}, inf = 2147483647;
const long long ll = 9223372036854775807;
struct node {
  char a;
  int b, c;
};
int main() {
  int a, b;
  while (cin >> a >> b) {
    int A[1024] = {};
    for (int i = 0; i < a; i++) {
      cin >> A[i];
    }
    vector<node> ans;
    int maxr = inf, id = 0;
    for (int i = 1; i <= 1000; i++) {
      int sum = 0;
      int now = i;
      for (int j = 0; j < a; j++) {
        if (A[j] != now) {
          sum++;
        }
        now += b;
      }
      if (sum < maxr) {
        maxr = sum;
        id = i;
      }
    }
    int now = id;
    for (int i = 0; i < a; i++) {
      if (A[i] > now) {
        node tmp;
        tmp.a = '+', tmp.b = i + 1, tmp.c = A[i] - now;
        ans.push_back(tmp);
      }
      if (A[i] < now) {
        node tmp;
        tmp.a = '-', tmp.b = i + 1, tmp.c = now - A[i];
        ans.push_back(tmp);
      }
      now += b;
    }
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++) {
      cout << ans[i].a << " " << ans[i].b << " " << ans[i].c << '\n';
    }
  }
  return 0;
}
