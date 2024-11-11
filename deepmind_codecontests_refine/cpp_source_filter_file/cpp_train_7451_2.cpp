#include <bits/stdc++.h>
using namespace std;
int n, m, q;
int arr[100005];
int ant[100005];
int sz[100005];
unordered_map<string, int> mp;
void init() {
  for (int i = 0; i < n; i++) {
    arr[i] = i;
    sz[i] = 1;
  }
  return;
}
int root(int a) {
  if (arr[a] != a) {
    arr[a] = root(arr[a]);
  }
  return arr[a];
}
bool find(int a, int b) {
  if (root(a) == root(b)) {
    return true;
  } else {
    return false;
  }
}
void un(int a, int b) {
  int root_a = root(a);
  int root_b = root(b);
  if (sz[root_a] >= sz[root_b]) {
    arr[root_b] = root_a;
    sz[root_a] += sz[root_b];
  } else {
    arr[root_a] = root_b;
    sz[root_b] += sz[root_a];
  }
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m >> q;
  init();
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    mp[s] = i;
  }
  for (int i = 0; i < m; i++) {
    int t;
    cin >> t;
    string a, b;
    cin >> a >> b;
    int ra = root(mp[a]), rb = root(mp[b]);
    bool flag = true;
    if (t == 1) {
      if (ant[ra] != 0 && rb == root(ant[ra])) {
        flag = false;
      } else {
        if (ant[ra] == 0 && ant[rb] != 0) {
          ant[ra] = ant[rb];
        } else if (ant[ra] != 0 && ant[rb] == 0) {
          ant[rb] = ant[ra];
        } else if (ant[ra] != 0 && ant[rb] != 0) {
          un(root(ant[ra]), root(ant[rb]));
        }
        un(ra, rb);
        ant[root(ra)] = ant[ra];
      }
    } else {
      if (ra == rb) {
        flag = false;
      } else {
        if (ant[ra] != 0) {
          un(ant[ra], rb);
        }
        if (ant[rb] != 0) {
          un(ant[rb], ra);
        }
        ant[ra] = root(rb);
        ant[rb] = root(ra);
      }
    }
    if (flag) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  while (q--) {
    string a, b;
    cin >> a >> b;
    int ra = root(mp[a]), rb = root(mp[b]);
    if (ra == rb) {
      cout << 1 << endl;
    } else if (ant[ra] != 0 && root(ant[ra]) == rb) {
      cout << 2 << endl;
    } else {
      cout << 3 << endl;
    }
  }
  return 0;
}
