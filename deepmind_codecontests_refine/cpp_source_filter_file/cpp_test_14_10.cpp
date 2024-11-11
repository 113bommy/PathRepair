#include <bits/stdc++.h>
using namespace std;
void print(int x) { cerr << x << "\n"; }
void print(long long x) { cerr << x << "\n"; }
void print(double x) { cerr << x << "\n"; }
void print(char x) { cerr << x << "\n"; }
void print(string x) { cerr << x << "\n"; }
template <class T>
void print(vector<T> v) {
  cerr << "[ ";
  for (T i : v) {
    print(i);
    cerr << " ";
  }
  cerr << "]";
  cerr << "\n";
}
template <class T>
void print(set<T> v) {
  cerr << "[ ";
  for (T i : v) {
    print(i);
    cerr << " ";
  }
  cerr << "]";
  cerr << "\n";
}
template <class T, class V>
void print(map<T, V> v) {
  cerr << endl << "[ \n";
  for (auto i = v.begin(); i != v.end(); i++) {
    print(i->first);
    cerr << " ";
    print(i->second);
    cerr << endl;
  }
  cerr << "]";
  cerr << "\n";
}
long long int bn(long long a, long long b, long long m) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % m;
    a = (a * a) % m;
    b >>= 1;
  }
  return res;
}
int max_index(int start, int end, int a[]) {
  int max = -20;
  int index = 1;
  for (int i = start; i <= end; i++) {
    if (a[i] >= max) {
      max = a[i];
      index = i;
    }
  }
  return index;
}
void solve() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n + 1];
    int b[n + 1];
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      b[i] = a[i];
    }
    sort(b + 1, b + n + 1);
    int k = 0;
    vector<vector<int> > ans;
    for (int i = n; i > 1; i--) {
      bool flag = true;
      for (int i = 1; i <= n; i++) {
        if (a[i] != b[i]) flag = false;
      }
      if (flag) break;
      int maxi = max_index(1, i, a);
      if (i == maxi) {
        continue;
      }
      print(maxi);
      vector<int> subans;
      int l = 1;
      int r = i;
      int d = maxi - l + 1;
      subans.push_back(l);
      subans.push_back(r);
      subans.push_back(d);
      ans.push_back(subans);
      k++;
      while (d--) {
        int temp = a[1];
        for (int j = 1; j < i; j++) {
          a[j] = a[j + 1];
        }
        a[i] = temp;
      }
    }
    cout << k << "\n";
    for (int i = 0; i < ans.size(); i++) {
      for (int j : ans[i]) {
        cout << j << " ";
      }
      cout << "\n";
    }
  }
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
  return 0;
}
