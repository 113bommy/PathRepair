#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
long long i, j, t;
bool flag = false;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long t = 1;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> v(n);
    unordered_map<long long, long long> mp1;
    for (i = 0; i < n; i++) {
      cin >> v[i];
      mp1[v[i]]++;
    }
    if (mp1[0] >= n / 2) {
      cout << mp1[0] << endl;
      continue;
    }
    long long len = 0;
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        if (i != j) {
          if (v[i] == 0 && v[j] == 0)
            len = max(len, mp1[0]);
          else {
            vector<long long> temp;
            long long a = v[i], b = v[j], next = a + b;
            temp.push_back(a);
            temp.push_back(b);
            mp1[a]--;
            mp1[b]--;
            while (mp1.find(next) != mp1.end() && mp1[next] > 0) {
              temp.push_back(next);
              mp1[next]--;
              a = b;
              b = next;
              next = a + b;
            }
            long long tsize = temp.size();
            len = max(len, tsize);
            for (auto i : temp) mp1[i]++;
          }
        }
      }
    }
    cout << len << endl;
  }
}
