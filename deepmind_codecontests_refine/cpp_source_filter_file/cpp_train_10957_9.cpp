#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    long long int flip = 0, idx = 0;
    vector<int> q;
    vector<int> q2;
    for (int i = n - 1; i >= 0; i--) {
      if (flip ^ ((a[idx]) == b[i])) q.push_back(1);
      q.push_back(i + 1);
      if (flip)
        idx += i;
      else {
        idx -= i;
      }
      flip = !flip;
    }
    cout << q.size() << " ";
    for (auto it = q.begin(); it != q.end(); it++) cout << *it << " ";
    cout << endl;
  }
}
