#include <bits/stdc++.h>
using namespace std;
int stack[410000], n, k, ans, size, bag, a[410000], tim[410000];
queue<int> q[410000];
bool vis[410000];
struct node {
  int num, T;
} heap[410000 * 2];
void put(int d) {
  int now, nxt;
  heap[++size].num = d;
  heap[size].T = tim[d];
  now = size;
  while (now > 1) {
    nxt = now >> 1;
    if (heap[now].T <= heap[nxt].T) break;
    swap(heap[now].num, heap[nxt].num);
    swap(heap[now].T, heap[nxt].T);
    now = nxt;
  }
}
int get() {
  int now, nxt, res;
  res = heap[1].num;
  heap[1].num = heap[size].num;
  heap[1].T = heap[size].T;
  size--;
  now = 1;
  while (now * 2 <= size) {
    nxt = now << 1;
    if (nxt < size && heap[nxt].T < heap[nxt + 1].T) nxt++;
    if (heap[now].T >= heap[nxt].T) break;
    swap(heap[now].num, heap[nxt].num);
    swap(heap[now].T, heap[nxt].T);
    now = nxt;
  }
  return res;
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    q[a[i]].push(i);
  }
  for (int i = 1; i <= n; i++) {
    tim[i] = q[i].front();
    q[i].pop();
    q[i].push(n + 1);
  }
  for (int i = 1; i <= n; i++) {
    if (!vis[a[i]]) {
      ans++;
      tim[a[i]] = q[a[i]].front();
      q[a[i]].pop();
      vis[a[i]] = true;
      if (bag < k)
        bag++;
      else {
        int now = get();
        while (!vis[now]) now = get();
        vis[now] = false;
      }
      put(a[i]);
    } else {
      tim[a[i]] = q[a[i]].front();
      q[a[i]].pop();
      put(a[i]);
    }
  }
  printf("%d\n", ans);
}
