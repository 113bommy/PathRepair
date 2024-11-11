#include <bits/stdc++.h>
using namespace std;
const int maxi = 10000007;
int ne[1500] = {0}, d[1500], us[1500] = {0};
int main() {
  int n, p;
  cin >> n >> p;
  int a, b, c;
  vector<int> s1, s2, s3;
  for (int i = 1; i <= p; i++) {
    cin >> a >> b >> c;
    ne[a] = b;
    us[b] = 1;
    d[a] = c;
  };
  for (int i = 1; i <= n; i++)
    if (us[i] == 0)
      if (ne[i] != 0) {
        int min = maxi;
        int j = i;
        while (ne[j] != 0) {
          if (d[j] < min) min = d[j];
          j = ne[j];
        };
        s1.push_back(i);
        s2.push_back(j);
        s3.push_back(min);
      };
  cout << s1.size() << "\n";
  for (int i = 0; i < s1.size(); i++)
    cout << s1[i] << ' ' << s2[i] << ' ' << s3[i] << "\n";
  return 0;
};
