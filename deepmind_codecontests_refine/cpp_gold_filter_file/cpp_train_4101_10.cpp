#include <bits/stdc++.h>
using namespace std;
int main() {
  clock_t cl = clock();
  vector<unsigned int> ips;
  unsigned int octet = 0xFF;
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = (0), endi = (n); i < endi; i++) {
    unsigned int cur, tot = 0;
    scanf("%d", &cur);
    tot |= cur << 24;
    scanf(".%d", &cur);
    tot |= cur << 16;
    scanf(".%d", &cur);
    tot |= cur << 8;
    scanf(".%d", &cur);
    tot |= cur;
    ips.push_back(tot);
  }
  sort((ips).begin(), (ips).end());
  unsigned int cv = ~((unsigned int)0);
  unsigned int lastGood = 5;
  for (int i = (0), endi = (32); i < endi; i++) {
    int diff = ips.size();
    for (int j = (0), endj = (ips.size() - 1); j < endj; j++) {
      if ((ips[j] & cv) == (ips[j + 1] & cv)) diff--;
    }
    if (diff == k) lastGood = cv;
    cv ^= ((unsigned int)1) << i;
  }
  if (lastGood == 5 || lastGood == 0)
    printf("-1\n");
  else {
    printf("%d.%d.%d.%d\n", (lastGood >> 24) & 0xFF, (lastGood >> 16) & 0xFF,
           (lastGood >> 8) & 0xFF, (lastGood >> 0) & 0xFF);
  }
  return 0;
}
