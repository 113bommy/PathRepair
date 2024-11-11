#include <bits/stdc++.h>
using namespace std;
int n;
int t[100005];
long long l[100005], r[100005];
vector<long long> Val;
int ST[800005], Lazy[800005];
void Push(int node, int l, int r) {
  if (Lazy[node] == -1) {
    return;
  }
  if (Lazy[node] == 2) {
    ST[node] = (r - l + 1) - ST[node];
  } else {
    ST[node] = Lazy[node] * (r - l + 1);
  }
  if (l != r) {
    if (Lazy[node] == 2) {
      if (Lazy[node << 1] == -1) {
        Lazy[node << 1] = 2;
      } else if (Lazy[node << 1] != 2) {
        Lazy[node << 1] ^= 1;
      } else {
        Lazy[node << 1] = -1;
      }
      if (Lazy[node << 1 | 1] == -1) {
        Lazy[node << 1 | 1] = 2;
      } else if (Lazy[node << 1 | 1] != 2) {
        Lazy[node << 1 | 1] ^= 1;
      } else {
        Lazy[node << 1 | 1] = -1;
      }
    } else {
      Lazy[node << 1] = Lazy[node];
      Lazy[node << 1 | 1] = Lazy[node];
    }
  }
  Lazy[node] = -1;
}
void Update(int node, int l, int r, int L, int R, int type) {
  Push(node, l, r);
  if (l > R or r < L) {
    return;
  }
  if (L <= l and r <= R) {
    Lazy[node] = type;
    Push(node, l, r);
    return;
  }
  int mid = (l + r) >> 1;
  Update(node << 1, l, mid, L, R, type);
  Update(node << 1 | 1, mid + 1, r, L, R, type);
  ST[node] = ST[node << 1] + ST[node << 1 | 1];
}
long long Get(int node, int l, int r) {
  if (l == r) {
    return Val[l];
  }
  int mid = (l + r) >> 1;
  Push(node << 1, l, mid);
  Push(node << 1 | 1, mid + 1, r);
  if (ST[node << 1] == mid - l + 1) {
    return Get(node << 1 | 1, mid + 1, r);
  }
  return Get(node << 1, l, mid);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  for (int i = 0; i <= 600000; i++) {
    Lazy[i] = -1;
  }
  cin >> n;
  Val.emplace_back(1);
  for (int i = 1; i <= n; i++) {
    cin >> t[i] >> l[i] >> r[i];
    t[i]--;
    if (t[i] != 2) {
      t[i] ^= 1;
    }
    Val.emplace_back(l[i]);
    Val.emplace_back(r[i] + 1);
  }
  sort(Val.begin(), Val.end());
  Val.erase(unique(Val.begin(), Val.end()), Val.end());
  for (int i = 1; i <= n; i++) {
    Update(1, 0, Val.size(),
           lower_bound(Val.begin(), Val.end(), l[i]) - Val.begin(),
           upper_bound(Val.begin(), Val.end(), r[i]) - Val.begin() - 1, t[i]);
    cout << Get(1, 0, Val.size()) << '\n';
  }
}
