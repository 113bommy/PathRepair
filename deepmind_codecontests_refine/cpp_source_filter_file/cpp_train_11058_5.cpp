#include <bits/stdc++.h>
using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");
vector<int> v[500001];
vector<vector<int>> v2(101), g2(101);
vector<pair<int, int>> vi[100001];
set<int> st;
int ph[2000001] = {0};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 0;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    n = 2 * n;
    long long a[n], s = INT_MAX, ans = 0;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    cout << a[n / 2] - a[(n / 2) - 1];
  }
  return 0;
}
