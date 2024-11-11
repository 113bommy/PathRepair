#include <bits/stdc++.h>
using namespace std;
struct triple {
  int x, y, z;
};
int n, k;
int a[300000];
int b[300000];
set<pair<int, int> > Left;
set<pair<int, int> > vere;
set<pair<int, int> > out1, out2;
vector<triple> d;
int main() {
  cin >> n;
  for (int i = 0; i < n * 3; i++) {
    cin >> a[i];
    a[i]--;
    b[a[i]] = i;
    Left.insert(make_pair(b[a[i]], a[i]));
  }
  d.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> d[i].x >> d[i].y >> d[i].z;
    d[i].x--;
    d[i].y--;
    d[i].z--;
  }
  cin >> k;
  k--;
  for (int i = 0; i < n; i++) {
    if ((k == d[i].x) || (k == d[i].y) || (k == d[i].z)) {
      if (k == d[i].y) {
        swap(d[i].y, d[i].x);
      }
      if (k == d[i].z) {
        swap(d[i].z, d[i].x);
      }
      if (Left.begin()->second == k) {
        Left.erase(Left.begin());
        int op1 = d[i].y, op2 = d[i].z;
        if (b[op1] > b[op2]) swap(op1, op2);
        Left.erase(make_pair(b[op1], op1));
        Left.erase(make_pair(b[op2], op2));
        out1.insert(make_pair(op1, b[op1]));
        out1.insert(make_pair(op2, b[op2]));
        for (set<pair<int, int> >::iterator it = vere.begin(); it != vere.end();
             it++) {
          if (it->second < op2)
            out1.insert(make_pair(it->second, it->first));
          else
            out2.insert(make_pair(it->second, it->first));
        }
        for (set<pair<int, int> >::iterator it = Left.begin(); it != Left.end();
             it++) {
          out2.insert(make_pair(it->second, it->first));
        }
        for (set<pair<int, int> >::iterator it = out1.begin(); it != out1.end();
             it++) {
          cout << it->first + 1 << " ";
        }
        for (set<pair<int, int> >::iterator it = out2.begin(); it != out2.end();
             it++) {
          cout << it->first + 1 << " ";
        }
        cout << endl;
        exit(0);
      } else {
        for (int i = 0; i < k; i++) {
          cout << i + 1 << " ";
        }
        for (int i = k + 1; i < n * 3; i++) {
          cout << i + 1 << " ";
        }
        cout << endl;
        exit(0);
      }
    } else {
      vere.insert(make_pair(b[d[i].x], d[i].x));
      vere.insert(make_pair(b[d[i].y], d[i].y));
      vere.insert(make_pair(b[d[i].z], d[i].z));
      Left.erase(make_pair(b[d[i].x], d[i].x));
      Left.erase(make_pair(b[d[i].y], d[i].y));
      Left.erase(make_pair(b[d[i].z], d[i].z));
    }
  }
  return 0;
}
