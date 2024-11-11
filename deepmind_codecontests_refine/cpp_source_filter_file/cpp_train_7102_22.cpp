#include <bits/stdc++.h>
using namespace std;
char s[100005];
int k;
vector<int> cur;
int main() {
  scanf("%s", s + 1);
  scanf("%d", &k);
  int n = strlen(s + 1);
  if (1ll * n * (n + 1) / 2 < k) {
    puts("No such Line.");
    return 0;
  }
  for (int i = 0; i < n; i++) cur.push_back(i);
  while (!cur.empty()) {
    vector<int> sub;
    int sum;
    char ch;
    int ncur = cur.size();
    for (ch = 'a'; ch <= 'z'; ch++) {
      sum = 0;
      for (int i = 0; i < ncur; i++)
        if (s[cur[i] + 1] == ch) sum += n - cur[i];
      if (sum < k)
        k -= sum;
      else
        break;
    }
    putchar(ch);
    int cnt = 0;
    for (int i = 0; i < ncur; i++)
      if (s[cur[i] + 1] == ch) {
        cnt++;
        if (cnt == k) return 0;
        sub.push_back(cur[i] + 1);
      }
    k -= cnt;
    cur = sub;
  }
  return 0;
}
