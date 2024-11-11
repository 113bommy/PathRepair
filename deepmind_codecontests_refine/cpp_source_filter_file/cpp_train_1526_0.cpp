#include <bits/stdc++.h>
const int maxN = (int)1e4 + 7;
const int maxM = (int)1e5 + 7;
const int maxT = (int)1e6 + 7;
using namespace std;
int n, a, b, grA, grB, z = 1;
vector<int> f, p;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> a >> b;
  for (int i = 1; i < n + 1; i++) f.push_back(i);
  while (true) {
    for (int i = 0; i < f.size(); i += 2) {
      if (f[i] == a || f[i + 1] == a || f[i] == b || f[i + 1] == b) {
        if ((f[i] == a && f[i + 1] == b) || (f[i] == b && f[i + 1] == a)) {
          if (f.size() == 2)
            cout << "FINAL!";
          else
            cout << z;
          return 0;
        } else {
          if (f[i] == a)
            p.push_back(f[i]);
          else if (f[i + 1] == a)
            p.push_back(f[i + 1]);
          else if (f[i] == b)
            p.push_back(f[i]);
          else if (f[i + 1] == b)
            p.push_back(f[i + 1]);
        }
      } else {
        int z = rand() % 2;
        z == 1 ? p.push_back(f[i]) : p.push_back(f[i + 1]);
      }
    }
    swap(f, p);
    p.clear();
    z++;
  }
}
