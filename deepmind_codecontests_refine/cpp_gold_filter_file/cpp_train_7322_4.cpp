#include <bits/stdc++.h>
using namespace std;
int ni() {
  int a;
  scanf("%d", &a);
  return a;
}
double nf() {
  double a;
  scanf("%lf", &a);
  return a;
}
char sbuf[100005];
string ns() {
  scanf("%s", sbuf);
  return sbuf;
}
long long nll() {
  long long a;
  scanf("%lld", &a);
  return a;
}
template <class T>
void out(T a, T b) {
  bool first = true;
  for (T i = a; i != b; ++i) {
    if (!first) printf(" ");
    first = false;
    cout << *i;
  }
  printf("\n");
}
template <class T>
void outl(T a, T b) {
  for (T i = a; i != b; ++i) {
    cout << *i << "\n";
  }
}
int n, m;
vector<int> ans;
long long a[100005];
int l, r, nl, nr;
const long long inf = 1000000000000000005;
bool mark[100005];
long long doit() {
  int i;
  ans.clear();
  if (nl > 0 && l == 0) return inf;
  if (nl >= l) {
    for (i = (0); i < (((n - 1))); ++i) ans.push_back(i >= nl ? i + 1 : i);
    reverse(&ans[0], &ans[l]);
    return a[nl] - a[0] + a[n - 1] - a[0];
  } else {
    for (i = (0); i < (((n - 1))); ++i) ans.push_back(i >= nl ? i + 1 : i);
    reverse(&ans[0], &ans[nl]);
    long long ret = a[nl] - a[0] + a[n - 1] - a[0];
    set<pair<int, int> > dst;
    int todo = l - nl;
    for (i = (0); i < (((n - 1 - todo))); ++i)
      if (i != nl && i != nl - 1 && i > nl) {
        dst.insert(make_pair(a[i + 1] - a[i], i));
      }
    memset(mark, 0, sizeof(mark));
    vector<int> takethem;
    vector<int> costthem;
    int bs = 0;
    long long bsa = a[n - 1] - a[n - todo - 1];
    long long zu = 0;
    for (i = (0); i < (((todo))); ++i) {
      int cbs = todo - i - 1;
      int id = n - 1 - todo + i;
      dst.insert(make_pair(a[id + 1] - a[id], id));
      zu += dst.begin()->first * 2;
      takethem.push_back(dst.begin()->second);
      costthem.push_back(dst.begin()->first);
      dst.erase(dst.begin());
      long long cur = a[n - 1] - a[n - cbs - 1] + zu;
      if (cur < bsa) {
        bsa = cur;
        bs = i + 1;
      }
    }
    for (i = (0); i < (((bs))); ++i) {
      ret += costthem[i] * 2;
      if (takethem[i] > nl) {
        mark[takethem[i] - 1] = 1;
      } else {
        assert(false);
        mark[nl - takethem[i] - 1] = 1;
      }
    }
    ret += a[n - 1] - a[n - (todo - bs) - 1];
    for (i = (0); i < (((todo - bs))); ++i) {
      mark[n - i - 3] = 1;
    }
    for (i = (0); i < (((n - 2))); ++i)
      if (mark[i]) {
        int j = i + 1;
        while (j < n - 2 && mark[j]) ++j;
        reverse(&ans[i], &ans[j + 1]);
        i = j;
      }
    return ret;
  }
}
int main() {
  int i, j, k;
  n = ni();
  l = ni();
  r = n - l - 1;
  nl = ni() - 1;
  nr = n - nl - 1;
  for (i = (0); i < (((n))); ++i) a[i] = nll();
  if (nl && !l || nr && !r) {
    printf("-1\n");
    return 0;
  }
  long long A = doit();
  reverse(a, a + n);
  for (i = (0); i < (((n))); ++i) a[i] = -a[i];
  swap(l, r);
  swap(nl, nr);
  long long B = doit();
  if (A < B) {
    reverse(a, a + n);
    for (i = (0); i < (((n))); ++i) a[i] = -a[i];
    swap(l, r);
    swap(nl, nr);
  }
  doit();
  if (B < A)
    for (i = (0); i < (((n))); ++i) ans[i] = n - ans[i];
  else
    for (i = (0); i < (((n))); ++i) ans[i]++;
  printf("%I64d\n", min(A, B));
  out((ans).begin(), (ans).end());
  return 0;
}
