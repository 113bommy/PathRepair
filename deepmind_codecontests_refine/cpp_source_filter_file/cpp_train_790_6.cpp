#include <bits/stdc++.h>
using namespace std;
string F[100010];
char str[1000];
int T[100010], e;
set<string> A, B, AB, BA, FA, FB;
vector<pair<string, string> > ans;
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%s%d", str, T + i);
    F[i] = string(str);
    if (T[i] == 1) e++;
  }
  for (int i = 1; i <= n; i++) {
    if (i <= e)
      A.insert(to_string(i));
    else
      B.insert(to_string(i));
  }
  for (int i = 1; i <= n; i++) {
    if (A.count(F[i])) {
      A.erase(F[i]);
      if (T[i] == 0) AB.insert(F[i]);
    } else if (B.count(F[i])) {
      B.erase(F[i]);
      if (T[i] == 1) BA.insert(F[i]);
    } else {
      if (T[i] == 1)
        FA.insert(F[i]);
      else
        FB.insert(F[i]);
    }
  }
  while (A.size() || B.size() || AB.size() || BA.size()) {
    if (A.size() && BA.size()) {
      ans.push_back({*BA.begin(), *A.begin()});
      A.erase(A.begin());
      B.insert(*BA.begin());
      BA.erase(BA.begin());
      continue;
    }
    if (B.size() && AB.size()) {
      ans.push_back({*AB.begin(), *B.begin()});
      B.erase(B.begin());
      A.insert(*AB.begin());
      AB.erase(AB.begin());
      continue;
    }
    if (A.size() && FA.size()) {
      ans.push_back({*FA.begin(), *A.begin()});
      A.erase(A.begin());
      FA.erase(FA.begin());
      continue;
    }
    if (B.size() && FB.size()) {
      ans.push_back({*FB.begin(), *B.begin()});
      B.erase(B.begin());
      FB.erase(FB.begin());
      continue;
    }
    ans.push_back({*AB.begin(), "tmp"});
    A.insert(*AB.begin());
    AB.erase(AB.begin());
    FB.insert("tmp");
  }
  printf("%d\n", (int)ans.size());
  for (pair<string, string>& x : ans)
    printf("move%s%s\n", x.first.c_str(), x.second.c_str());
  return 0;
}
