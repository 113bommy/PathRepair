#include <bits/stdc++.h>
using namespace std;
long long arr[200000], pos[200000];
vector<pair<long long, int> > subf;
const int largo = 1 << 19;
struct st {
  int l, r, v;
};
int ini, fin;
st ST[largo];
int Query(int i) {
  if (ini > ST[i].r || fin < ST[i].l)
    return 0;
  else if (ST[i].l >= ini && fin >= ST[i].r)
    return ST[i].v;
  return Query(i * 2) + Query(i * 2 + 1);
}
void Update(int p) {
  p += largo / 2;
  ST[p].v = 1;
  while (p /= 2) ST[p].v = ST[p * 2].v + ST[p * 2 + 1].v;
}
int main() {
  int n;
  for (int i = largo / 2; i < largo; i++)
    ST[i].l = i - largo / 2, ST[i].r = i - largo / 2, ST[i].v = 0;
  for (int i = largo / 2 - 1; i > 0; i--)
    ST[i].l = ST[i * 2].l, ST[i].r = ST[i * 2 + 1].r, ST[i].v = 0;
  long long acum = 0, T;
  cin >> n >> T;
  for (int i = 0; i < n; i++) {
    long long a;
    scanf("%lld", &a);
    acum += a;
    arr[i] = a;
    subf.push_back({acum, i});
  }
  sort(subf.begin(), subf.end());
  for (int i = 0; i < n; i++) pos[subf[i].second] = i;
  long long ret = 0;
  ini += 0;
  for (int i = 0; i < n; i++) {
    int p = upper_bound(subf.begin(), subf.end(), pair<long long, int>(T, 0)) -
            subf.begin();
    fin = p - 1;
    p -= Query(1);
    ret += p;
    T += arr[i];
    Update(pos[i]);
  }
  cout << ret << endl;
}
