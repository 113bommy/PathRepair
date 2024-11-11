#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 85 - 69, maxl = 62;
const long long int Mod = 1000001;
long long int a[maxn];
long long int valu;
int n;
int Log[Mod];
void build_Log(void) {
  memset(Log, -1, sizeof Log);
  long long int val = 1;
  for (int i = 0; i < maxl; i++) {
    if (~Log[val]) assert(0);
    Log[val] = i;
    val += val;
    if (val >= Mod) val -= Mod;
  }
  return;
}
int rightmost(long long int x) { return Log[(x & -x) % Mod]; }
struct ABOO {
  long long int arr[maxn];
  long long int base[maxl];
  int basecnt;
  ABOO() { memset(base, -1, sizeof base); }
  void build_base(int id = 0) {
    if (id == n) return;
    for (int i = 0; i < maxl; i++)
      if (((arr[id] >> i) & 1LL) and ~base[i]) arr[id] ^= base[i];
    if (arr[id]) {
      int x = rightmost(arr[id]);
      for (int i = 0; i < maxl; i++)
        if (base[i] != -1LL and ((base[i] >> x) & 1LL)) base[i] ^= arr[id];
      basecnt++;
      base[x] = arr[id];
    }
    build_base(id + 1);
  }
  bool can_generate(long long int x) {
    for (int i = 0; x and i < maxl; i++)
      if (((x >> i) & 1LL) and base[i] != -1LL) x ^= base[i];
    return x ? false : true;
  }
  long long int &operator[](int i) { return arr[i]; }
} b;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  build_Log();
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    valu ^= a[i];
    b[i] ^= a[i];
  }
  b.build_base();
  if (!b.can_generate(valu))
    cout << "1/1";
  else
    cout << (1LL << b.basecnt) - 1 << "/" << (1LL << b.basecnt);
  return 0;
}
