#include <bits/stdc++.h>
using namespace std;
long long mod(long long a, long long m) {
  if (a < 0)
    return (a + m) % m;
  else
    return a % m;
}
long long pow1(long long a, long long p, long long m) {
  if (p == 0) {
    return 1;
  }
  if (p % 2 == 0) {
    long long r = pow1(a, p / 2, m);
    return (r * r) % m;
  } else {
    return (a * pow1(a, p - 1, m)) % m;
  }
}
int main() {
  int n;
  cin >> n;
  int a;
  vector<int> s(n);
  priority_queue<pair<int, int> > q;
  int x[3];
  int l = -1;
  for (int i = 0; i < n; i++) {
    cin >> a;
    s[i] = a;
    if (a == 0) {
      for (int j = l + 1; j < i; j++) {
        q.push(make_pair(-s[j], j));
      }
      x[0] = x[1] = x[2] = 10000000;
      for (int j = 0; j < 3; j++) {
        if (q.empty()) break;
        x[j] = q.top().second;
        q.pop();
      }
      while (!q.empty()) q.pop();
      sort(x, x + 3);
      if (x[0] != 10000000) {
        int num = 1;
        for (int j = l + 1; j <= x[0]; j++) {
          cout << "pushStack" << endl;
        }
        if (x[1] != 10000000) {
          num++;
          for (int j = x[0] + 1; j < x[1]; j++) {
            cout << "pushBack" << endl;
          }
          cout << "pushQueue" << endl;
          if (x[2] != 10000000) {
            num++;
            for (int j = x[1] + 1; j < x[2]; j++) {
              cout << "pushQueue" << endl;
            }
            cout << "pushFront" << endl;
            for (int j = x[2] + 1; j < i; j++) {
              cout << "pushBack" << endl;
            }
          }
        }
        cout << num << " popStack";
        if (x[1] != 10000000) cout << " popQueue";
        if (x[2] != 10000000) cout << " popFront";
        cout << endl;
      } else
        cout << 0 << endl;
      l = i;
    }
  }
  for (int i = l + 1; i < n; i++) {
    cout << "pushBack" << endl;
  }
}
