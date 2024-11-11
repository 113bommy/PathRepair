#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000;
bool isLucky(int x) {
  while (x) {
    if (x % 10 == 4 || x % 10 == 7)
      x /= 10;
    else
      return false;
  }
  return true;
}
long long calc(int len) { return (len + 1) * (long long)len / 2; }
int n;
int a[MAXN + 10];
vector<int> allPos;
vector<int> pos[1000 + 10];
int main() {
  scanf("%d", &n);
  vector<int> luckys;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    if (isLucky(a[i])) {
      luckys.push_back(a[i]);
    }
  }
  sort(luckys.begin(), luckys.end());
  luckys.erase(unique(luckys.begin(), luckys.end()), luckys.end());
  for (int i = 1; i <= n; i++) {
    if (!isLucky(a[i]))
      a[i] = 0;
    else {
      a[i] =
          lower_bound(luckys.begin(), luckys.end(), a[i]) - luckys.begin() + 1;
      pos[a[i]].push_back(i);
      allPos.push_back(i);
    }
  }
  long long finalAns = 0;
  for (size_t i = 0; i < allPos.size(); i++) {
    static bool inserted[1000 + 10];
    memset(inserted, 0, sizeof(inserted));
    long long ans = calc(allPos[i] - 1);
    set<int> seq;
    for (size_t j = i; j < allPos.size(); j++) {
      int ps = allPos[j];
      if (!inserted[a[ps]]) {
        inserted[a[ps]] = true;
        for (size_t k = 0; k < pos[a[ps]].size(); k++)
          if (pos[a[ps]][k] < allPos[i]) {
            set<int>::iterator it = seq.lower_bound(pos[a[ps]][k]);
            set<int>::iterator bakIt = it;
            int begin = it == seq.begin() ? 0 : *--it;
            it = bakIt;
            int end = it == seq.end() ? allPos[i] : *it;
            ans -= calc(end - begin - 1);
            ans += calc(pos[a[ps]][k] - begin - 1);
            ans += calc(end - pos[a[ps]][k] - 1);
            seq.insert(pos[a[ps]][k]);
          }
      }
      int lastPos = i == 0 ? 0 : allPos[i - 1];
      int nextPos = j == allPos.size() - 1 ? n + 1 : allPos[j + 1];
      int lastLen = allPos[i] - (seq.empty() ? 0 : *seq.rbegin()) - 1;
      for (int m = 0; m < allPos[i] - lastPos; m++) {
        long long tmp = (ans - (lastLen + lastLen - m + 1) * (long long)m / 2) *
                        (nextPos - allPos[j]);
        finalAns += tmp;
      }
    }
  }
  for (size_t i = 0; i <= allPos.size(); i++) {
    int begin = i == 0 ? 0 : allPos[i - 1];
    int end = i == allPos.size() ? n + 1 : allPos[i];
    for (int j = begin + 1; j < end; j++) {
      finalAns += calc(j - 1) * calc(end - j);
    }
  }
  cout << finalAns << endl;
  return 0;
}
