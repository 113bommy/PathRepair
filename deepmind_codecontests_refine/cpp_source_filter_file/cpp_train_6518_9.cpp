#include <bits/stdc++.h>
using namespace std;
struct jt {
  long long int a, b, c, d, e;
};
long long int man(jt d1, jt d2) {
  return d1.a * d2.a + d1.b * d2.b + d1.c * d2.c + d1.d * d2.d + d1.e * d2.e;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  ;
  long long int n;
  cin >> n;
  if (n > 10)
    cout << "0";
  else {
    jt arr[n];
    for (long long int i = 0; i < n; i++)
      cin >> arr[i].a >> arr[i].b >> arr[i].c >> arr[i].d >> arr[i].e;
    vector<long long int> ans;
    for (long long int i = 0; i < n; i++) {
      bool f = 0;
      for (long long int j = 0; j < n; j++) {
        for (long long int k = 0; k < n; k++) {
          if (i != j && j != k && !f) {
            jt t1 = {arr[i].a - arr[j].a, arr[i].b - arr[j].b,
                     arr[i].c - arr[j].c, arr[i].d - arr[j].d,
                     arr[i].e - arr[j].e};
            jt t2 = {arr[i].a - arr[k].a, arr[i].b - arr[k].b,
                     arr[i].c - arr[k].c, arr[i].d - arr[k].d,
                     arr[i].e - arr[k].e};
            long double d1 = (long double)(man(t1, t2));
            long double d2 = sqrt(man(t1, t1)) * sqrt(man(t2, t2));
            long double d3 = (long double)(acos(d1 / d2));
            if (d3 < acos(0)) {
              f = 1;
            }
          }
        }
      }
      if (!f) ans.push_back(i + 1);
    }
    cout << ans.size() << endl;
    for (long long int i = 0; i < ans.size(); i++) {
      cout << ans[i] << endl;
    }
  }
}
