#include <bits/stdc++.h>
using namespace std;
bitset<8000> adjMat[8000];
pair<int, int> out[8000];
int main() {
  int i, j, k;
  int n;
  char c;
  scanf("%d\n", &n);
  for (i = 0; i < n; i++) {
    for (j = 0; j < n / 4; j++) {
      c = getchar();
      c = ((c >= '0') && (c <= '9')) ? (c - '0') : (c - 'A' + 10);
      for (k = 0; k < 4; k++) {
        if (c & (1 << (3 - k))) adjMat[i][4 * j + k] = 1;
      }
    }
    getchar();
  }
  long long int ans = 0;
  for (i = 0; i < n; i++) out[i] = make_pair(adjMat[i].count(), i);
  sort(out, out + n);
  for (i = n - 1; i >= 0; i--) {
    if (out[i].first == i)
      ans += i + 614 * n * i;
    else
      break;
  }
  if (i < 0) {
    printf("%lld\n", ans);
    return 0;
  }
  vector<int> v, vv, vv2;
  for (; i >= 0; i--) v.push_back(out[i].second);
  swap(v[0], v.back());
  for (i = 1; i < v.size(); i++) {
    if (adjMat[v[0]][v[i]]) {
      int c = 0;
      for (j = 1; j < v.size(); j++) {
        if (adjMat[v[j]][v[0]] && adjMat[v[i]][v[j]]) c++;
      }
      vv.push_back(c);
    }
  }
  sort(vv.begin(), vv.end());
  for (i = 1; i <= v.size() - vv.size(); i++)
    vv2.push_back(lower_bound(vv.begin(), vv.end(), i) - vv.begin());
  for (i = 0; i < vv.size(); i++) {
    ans += vv.size() - i - 1 + vv[i];
    ans += 2 * (vv2[vv[i] - 1] + (vv2.size() - vv[i]));
    ans += 3 * (i - vv2[vv[i] - 1]);
  }
  for (i = 0; i < vv2.size(); i++) {
    ans += vv2.size() - i - 1 + vv2[i];
    if (vv2[i] > 0) {
      ans += 2 * (vv[vv2[i] - 1] + vv.size() - vv2[i]);
      ans += 3 * (i - vv[vv2[i] - 1]);
    } else {
      ans += 2 * vv.size();
      ans += 3 * i;
    }
  }
  printf("%lld\n", ans);
  return 0;
}
