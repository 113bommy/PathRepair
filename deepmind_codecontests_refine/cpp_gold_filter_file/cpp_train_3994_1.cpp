#include <bits/stdc++.h>
using namespace std;
const int MaxN = 1e5 + 15;
int n, k, l, r, razliciti, niz[MaxN], cnt[MaxN];
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> niz[i];
    if (cnt[niz[i]]++ == 0) razliciti++;
  }
  if (razliciti < k) {
    cout << "-1 -1\n";
    return 0;
  }
  for (l = 0; razliciti > k || (razliciti == k && cnt[niz[l]] > 1);
       cnt[niz[l++]]--)
    if (cnt[niz[l]] == 1) razliciti--;
  for (r = n - 1; cnt[niz[r]] > 1; cnt[niz[r--]]--)
    ;
  cout << l + 1 << " " << r + 1 << endl;
  return 0;
}
