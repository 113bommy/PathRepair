#include <bits/stdc++.h>
using namespace std;
long long n, k;
int a[300000];
long long maxx;
long long pre[300000];
int main() {
  maxx = 1e18;
  maxx = maxx * 2;
  cin >> n >> k;
  a[0] = 0;
  set<int> v;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] != 1) {
      v.insert(i);
    }
  }
  for (int i = 1; i <= n; i++) {
    pre[i] += pre[i - 1];
    pre[i] += a[i];
  }
  a[n + 1] = 1e18;
  v.insert(n + 1);
  long long answer = 0;
  for (int i = 1; i <= n; i++) {
    long long s = a[i];
    long long p = a[i];
    long long lastid = i;
    int indx = i + 1;
    while (true) {
      set<int>::iterator itr = v.lower_bound(indx);
      if (itr == v.end()) break;
      int temp2 = *itr;
      indx = temp2 + 1;
      long long dis = temp2 - lastid - 1;
      if (p % k == 0) {
        long long my = p / k;
        my -= s;
        if (my >= 0) {
          my -= dis;
          if (my <= 0) answer++;
        }
      }
      lastid = temp2;
      s = pre[temp2] - pre[i - 1];
      long long temp = a[temp2];
      long long last = p;
      p = p * temp;
      if (p > maxx || ((p / last) != temp)) break;
    }
  }
  cout << answer << endl;
}
