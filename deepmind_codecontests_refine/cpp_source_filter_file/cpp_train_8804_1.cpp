#include <bits/stdc++.h>
using namespace std;
struct data {
  int r;
  int R;
  int h;
};
long long tree[10000000];
long long query(long long tree[], long long l, long long r, long long L,
                long long R, long long node) {
  if (l <= L && R <= r) {
    return tree[node];
  } else if (r < L || R < l)
    return 0;
  else {
    long long mid;
    mid = (L + R) / 2;
    return max(query(tree, l, r, L, mid, node * 2),
               query(tree, l, r, mid + 1, R, node * 2 + 1));
  }
}
void update(long long tree[], long long pos, long long L, long long R,
            long long node, long long value) {
  if (L == R && R == pos) {
    tree[node] = max(value, tree[node]);
    return;
  } else {
    long long mid;
    mid = (L + R) / 2;
    if (pos <= mid)
      update(tree, pos, L, mid, node * 2, value);
    else
      update(tree, pos, mid + 1, R, node * 2 + 1, value);
    tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
    return;
  }
}
bool comp(data a, data b) {
  if (a.R != b.R)
    return a.R < b.R;
  else
    return a.r > b.r;
}
map<long long, long long> freq;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n;
  cin >> n;
  data a[n];
  long long count = 0;
  set<long long> s;
  for (long long i = 0; i < n; i++) {
    cin >> a[i].r >> a[i].R >> a[i].h;
    s.insert(a[i].r);
    s.insert(a[i].R);
  }
  for (auto &node : s) {
    freq[node] = count++;
  }
  sort(a, a + n, comp);
  long long ans = 0;
  for (long long i = 0; i < n; i++) {
    long long temp =
        query(tree, freq[a[i].r] + 1, 1000000, 0, 1000000, 1) + a[i].h;
    update(tree, freq[a[i].R], 0, 1000000, 1, temp);
    ans = max(ans, temp);
  }
  cout << ans;
}
