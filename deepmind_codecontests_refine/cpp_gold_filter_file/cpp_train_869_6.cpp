#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:256000000")
using namespace std;
const double PI = acos(-1.0);
const int INF = 1000000000;
const int MOD = 1000000007;
const int M = INF;
template <class T>
void read(vector<T>& a) {
  for (int i = 0; i < a.size(); i++) cin >> a[i];
}
int main() {
  double TIME_START = clock();
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  double d;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> d;
  }
  vector<int> len(n, 1);
  for (int i = 1; i < n; i++)
    for (int j = 0; j < i; j++)
      if (a[i] >= a[j]) {
        len[i] = max(len[j] + 1, len[i]);
      }
  cout << n - *max_element(len.begin(), len.end());
  return 0;
}
