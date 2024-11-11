#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
      v[i] = (s[i] - '0' - 1);
    }
    unordered_map<int, int> umap;
    int sum = 0;
    long count = 0;
    for (int i = 0; i < n; i++) {
      sum += v[i];
      if (sum == 0) {
        count++;
      }
      if (umap.find(sum) != umap.end()) {
        count += (long long)umap[sum];
      }
      umap[sum]++;
    }
    cout << count << endl;
  }
}
