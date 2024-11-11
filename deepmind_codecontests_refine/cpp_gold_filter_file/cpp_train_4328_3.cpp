#include <bits/stdc++.h>
using namespace std;
int n;
int l[100005];
int r[100005];
int la[100005];
int ra[100005];
long long L, R;
pair<long long, int> demetrio;
int main() {
  L = 0, R = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &l[i], &r[i]);
    L += l[i];
    R += r[i];
  }
  demetrio = make_pair(llabs(R - L), -19);
  for (int i = 0; i < n; i++) {
    la[i] = L - l[i] + r[i];
    ra[i] = R - r[i] + l[i];
    if (llabs(ra[i] - la[i]) > demetrio.first) {
      demetrio = make_pair(llabs(ra[i] - la[i]), i);
    }
  }
  if (demetrio.second < 0)
    puts("0");
  else {
    printf("%d\n", demetrio.second + 1);
  }
  return 0;
}
