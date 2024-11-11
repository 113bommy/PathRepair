#include <bits/stdc++.h>
using namespace std;
char s[100001];
int n, k;
string ans;
long long cnt[26];
int main() {
  scanf("%s %d", s, &k);
  n = strlen(s);
  vector<int> a;
  for (int i = 0; i < n; i++) a.push_back(i);
  while (k > 0) {
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < a.size(); i++)
      if (a[i] + ans.size() < n)
        cnt[s[a[i] + ans.size()] - 'a'] += n - a[i] - ans.size();
    int p = 0;
    while (p < 26 && cnt[p] < k) {
      k -= cnt[p];
      p++;
    }
    if (p == 26) {
      puts("No such line.");
      return 0;
    }
    vector<int> t;
    for (int i = 0; i < a.size(); i++)
      if (a[i] + ans.size() < n && s[a[i] + ans.size()] == 'a' + p)
        t.push_back(i);
    swap(t, a);
    ans += p + 'a';
    k -= a.size();
  }
  printf("%s\n", ans.c_str());
  return 0;
}
