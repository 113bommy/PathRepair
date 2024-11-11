#include <bits/stdc++.h>
using namespace std;
int k[3], cnt[5555];
int main() {
  cin >> k[0] >> k[1] >> k[2];
  for (int i = 0; i < 3; ++i) cnt[k[i]]++;
  if (cnt[1] > 0)
    puts("YES");
  else if (cnt[2] >= 2)
    puts("YES");
  else if (cnt[3] >= 3)
    puts("YES");
  else if (cnt[2] == 1 && cnt[4] == 2)
    puts("YES");
  else
    puts("NO");
  return 0;
}
