#include <bits/stdc++.h>
using namespace std;
const long long inf = 1LL << 61;
const long long mod = 1000000007;
const int maxn = 200010;
map<int, int> mymap;
bool flag[maxn];
int arr[maxn];
int main() {
  int i = 0, j = 0, k = 0;
  int n, m, csum = 0;
  int rep = 0, odd_num = 0, eve_num = 0;
  scanf("%d%d", &n, &m);
  memset(flag, 0, sizeof(flag));
  for (i = 1; i <= n; i++) {
    scanf("%d", &j);
    if (mymap[j]) {
      flag[i] = true;
      rep++;
      continue;
    }
    arr[i] = j;
    mymap[j] = 1;
    if (j % 2)
      odd_num++;
    else
      eve_num++;
  }
  int ruin_odd = 0, ruin_eve = 0;
  int gen_odd = 0, gen_eve = 0;
  if (odd_num > eve_num) {
    int diff = odd_num - eve_num;
    if (rep <= diff) {
      gen_odd = 0;
      ruin_odd = (diff - rep) >> 1;
      gen_eve = rep + ruin_odd;
    } else {
      gen_odd = (rep - diff) >> 1;
      gen_eve = diff + (rep - diff) >> 1;
    }
  } else {
    int diff = eve_num - odd_num;
    if (rep <= diff) {
      gen_eve = 0;
      ruin_eve = (diff - rep) >> 1;
      gen_odd = rep + ruin_eve;
    } else {
      gen_eve = (rep - diff) >> 1;
      gen_odd = diff + (rep - diff) >> 1;
    }
  }
  csum = gen_odd + gen_eve;
  for (i = 1, j = 0; i <= n, j < ruin_odd; i++) {
    if (flag[i]) continue;
    if (arr[i] % 2) {
      flag[i] = true;
      j++;
      mymap[arr[i]] = 0;
    }
  }
  for (i = 1, j = 0; i <= n, j < ruin_eve; i++) {
    if (flag[i]) continue;
    if (arr[i] % 2 == 0) {
      flag[i] = true;
      j++;
    }
  }
  vector<int> evec, ovec;
  for (i = 1, j = 0; j < gen_odd; i += 2) {
    if (i > m) {
      puts("-1");
      return 0;
    }
    if (mymap[i]) continue;
    ovec.push_back(i);
    j++;
  }
  for (i = 2, j = 0; j < gen_eve; i += 2) {
    if (i > m) {
      puts("-1");
      return 0;
    }
    if (mymap[i]) continue;
    evec.push_back(i);
    j++;
  }
  for (i = 0, j = 0; j < evec.size(); j++) {
    for (; i <= n; i++) {
      if (flag[i]) {
        flag[i] = false;
        arr[i] = evec[j];
        break;
      }
    }
  }
  for (i = 0, j = 0; j < ovec.size(); j++) {
    for (; i <= n; i++) {
      if (flag[i]) {
        flag[i] = false;
        arr[i] = ovec[j];
        break;
      }
    }
  }
  printf("%d\n", csum);
  for (i = 1; i <= n; i++) {
    printf("%d%c", arr[i], i == n ? '\n' : ' ');
  }
  return 0;
}
