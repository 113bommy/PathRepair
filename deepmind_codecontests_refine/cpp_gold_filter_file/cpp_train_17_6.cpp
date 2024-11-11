#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 100;
struct node {
  int id;
  int num;
};
node s[maxn];
int b[maxn];
int num[maxn];
bool cmp(node a, node b) {
  if (a.num != b.num)
    return a.num > b.num;
  else
    return a.id < b.id;
}
struct ask {
  int id;
  int L = 0;
  int pos;
};
ask A[maxn];
bool cmp2(ask a, ask b) { return a.L < b.L; }
int ans[maxn];
int main() {
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  for (int i = 1; i <= N; i++) cin >> num[i];
  for (int i = 1; i <= N; i++) s[i].num = num[i], s[i].id = i;
  sort(s + 1, s + 1 + N, cmp);
  for (int i = 1; i <= N; i++) b[i] = s[i].id;
  int Q;
  cin >> Q;
  for (int i = 1; i <= Q; i++) {
    cin >> A[i].L;
    A[i].id = i;
    cin >> A[i].pos;
  }
  sort(A + 1, A + 1 + Q, cmp2);
  for (int i = 1; i <= Q; i++) {
    if (A[i].L != A[i - 1].L) sort(b + 1, b + 1 + A[i].L);
    ans[A[i].id] = b[A[i].pos];
  }
  for (int i = 1; i <= Q; i++) cout << num[ans[i]] << endl;
  return 0;
}
