#include <bits/stdc++.h>
using namespace std;
typedef struct z {
  long long a, b;
} me;
me ls[100009];
pair<int, int> p;
map<pair<int, int>, int> vis;
map<long long, int> mp;
map<long long, int> m;
int arr[100009];
int brr[100009];
struct Z {
  long long a, b, c;
};
vector<Z> V;
vector<Z> v;
int main() {
  int j = 0, k = 0;
  for (int i = 0; i < 8; i++) {
    cin >> ls[i].a >> ls[i].b;
    int q = ls[i].a;
    int r = ls[i].b;
    p = make_pair(q, r);
    vis[p] = 1;
    if (mp[ls[i].a] == 0) {
      arr[j++] = ls[i].a;
      mp[ls[i].a] = 1;
    }
    if (m[ls[i].b] == 0) {
      brr[k++] = ls[i].b;
      m[ls[i].b] = 1;
    }
  }
  sort(arr, arr + j);
  sort(brr, brr + k);
  for (int i = 0; i < j; i++) {
    for (int h = i + 1; h < j; h++) {
      for (int p = h + 1; p < j; p++) {
        Z tp;
        tp.a = arr[i];
        tp.b = arr[h];
        tp.c = arr[p];
        V.push_back(tp);
      }
    }
  }
  for (int i = 0; i < k; i++) {
    for (int h = i + 1; h < k; h++) {
      for (int p = h + 1; p < k; p++) {
        Z tp;
        tp.a = brr[i];
        tp.b = brr[h];
        tp.c = brr[p];
        v.push_back(tp);
      }
    }
  }
  int len1 = V.size();
  int len2 = v.size();
  for (int i = 0; i < len1; i++) {
    for (int j = 0; j < len2; j++) {
      Z tm = V[i];
      Z tp = v[i];
      int ar[99];
      ar[0] = tm.a;
      ar[1] = tm.b;
      ar[2] = tm.c;
      int br[99];
      br[0] = tp.a;
      br[1] = tp.b;
      br[2] = tp.c;
      int f = 0;
      for (int k = 0; k < 3; k++) {
        for (int h = 0; h < 3; h++) {
          p = make_pair(ar[k], br[h]);
          if (k != 1 && h != 1) {
          } else {
            if (vis[p] == 0) f = 1;
          }
        }
      }
      p = make_pair(ar[1], br[1]);
      if (f == 0 && vis[p] == 0) {
        cout << "respectable\n";
        return 0;
      }
    }
  }
  cout << "ugly\n";
  return 0;
}
