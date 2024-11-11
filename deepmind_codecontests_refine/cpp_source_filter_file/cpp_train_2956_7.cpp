#include <bits/stdc++.h>
using namespace std;
const long double Pi = 3.141592653;
const long long mod = 1e6 + 3;
class Graph {
  map<int, vector<int>> ma;

 public:
  void addedge(int n, int m) {
    ma[n].push_back(m);
    ma[m].push_back(n);
  }
};
int main() {
  long long n, m;
  cin >> n >> m;
  long long a[100001];
  a[0] = 0;
  for (int i = 1; i <= n; i++) {
    long long aa, b;
    cin >> aa >> b;
    a[i] = a[i - 1] + aa * b;
  }
  int song = 1;
  while (m--) {
    long long v;
    cin >> v;
    if (v > a[song]) {
      song += 1;
    }
    cout << song << endl;
  }
  return 0;
}
