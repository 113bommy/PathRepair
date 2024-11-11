#include <bits/stdc++.h>
using namespace std;
inline void print(int n) {
  if (n == 0) {
    putchar('0');
    putchar('\n');
  } else if (n == -1) {
    putchar('-');
    putchar('1');
    putchar('\n');
  } else {
    char buf[11];
    buf[10] = '\n';
    int i = 9;
    while (n) {
      buf[i--] = n % 10 + '0';
      n /= 10;
    }
    while (buf[i] != '\n') putchar(buf[++i]);
  }
}
int read() {
  int cc = getc(stdin);
  for (; cc < '0' || cc > '9';) cc = getc(stdin);
  int ret = 0;
  for (; cc >= '0' && cc <= '9';) {
    ret = ret * 10 + cc - '0';
    cc = getc(stdin);
  }
  return ret;
}
long long power(long long num, long long g) {
  if (g == 0) return 1;
  if (g % 2 == 1) return (num * power((num * num), g / 2));
  return power((num * num), g / 2);
}
int tree[800005];
void built(int start, int end, int index) {
  if (start == end) {
    tree[index] = 0;
    return;
  }
  int mid = (start + end) / 2;
  built(start, mid, 2 * index);
  built(mid + 1, end, 1 + 2 * index);
}
void update(int start, int end, int index, int ind) {
  if (start == end) {
    tree[index] = 1;
    return;
  }
  int mid = (start + end) / 2;
  if (ind <= mid)
    update(start, mid, 2 * index, ind);
  else
    update(mid + 1, end, 2 * index + 1, ind);
  tree[index] = tree[2 * index] + tree[2 * index + 1];
}
int search(int start, int end, int index, int l, int r) {
  if (start > r || end < l) return 0;
  if (start >= l && end <= r) return tree[index];
  int mid = (start + end) / 2;
  return search(start, mid, 2 * index, l, r) +
         search(mid + 1, end, 2 * index + 1, l, r);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  int a[n + 1];
  priority_queue<pair<int, int>, vector<pair<int, int> >,
                 greater<pair<int, int> > >
      pq;
  for (int i = 0; i < n; i++) {
    cin >> a[i + 1];
    pq.push(make_pair(a[i + 1], -i - 1));
  }
  int q;
  cin >> q;
  pair<pair<int, int>, int> pa[q];
  for (int i = 0; i < q; i++) {
    cin >> pa[i].first.first >> pa[i].first.second;
    pa[i].second = i;
  }
  int ans[q];
  sort(pa, pa + q);
  int z = q - 1;
  int hd = n;
  while (z >= 0) {
    while (z >= 0 && pa[z].first.first == hd) {
      int start = 1, end = n;
      while (start < end) {
        int mid = (start + end) / 2;
        int sd = search(1, n, 1, 1, mid);
        if (mid - sd >= pa[z].first.second)
          end = mid;
        else
          start = mid + 1;
      }
      ans[pa[z].second] = a[start];
      z--;
    }
    int sd = -pq.top().second;
    update(1, n, 1, sd);
    pq.pop();
    hd--;
  }
  for (int i = 0; i < q; i++) {
    cout << ans[i] << endl;
  }
  return 0;
}
