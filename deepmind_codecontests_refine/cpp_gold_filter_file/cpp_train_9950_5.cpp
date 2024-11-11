#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv) {
  char a[100001] = {};
  char b[100001] = {};
  scanf("%s", a);
  scanf("%s", b);
  size_t alen = strlen(a);
  size_t blen = strlen(b);
  char* aend = a + alen;
  char* cura = a;
  char* curb = b;
  std::vector<int> prefixes;
  prefixes.reserve(blen);
  prefixes.push_back(-1);
  for (size_t i = 0; i < blen; ++i) {
    while (cura != aend) {
      if (*curb == *cura) {
        prefixes.push_back(cura - a);
        ++cura;
        break;
      }
      ++cura;
    }
    if (cura == aend) break;
    ++curb;
  }
  cura = a + alen - 1;
  curb = b + blen - 1;
  std::vector<int> postfix;
  postfix.reserve(blen);
  postfix.push_back(alen);
  for (size_t i = 0; i < blen; ++i) {
    while (cura != a - 1) {
      if (*curb == *cura) {
        postfix.push_back(cura - a);
        --cura;
        break;
      }
      --cura;
    }
    if (cura == a - 1) break;
    --curb;
  }
  int curMax = -1;
  int curPostfixIdx = postfix.size() - 1;
  std::pair<int, int> res;
  for (int i = 0; i < prefixes.size() && curPostfixIdx >= 0; ++i) {
    while (blen - curPostfixIdx <= i || prefixes[i] >= postfix[curPostfixIdx]) {
      --curPostfixIdx;
      if (curPostfixIdx < 0) break;
    }
    if (curMax <= (i + curPostfixIdx)) {
      curMax = i + curPostfixIdx;
      res.first = i;
      res.second = curPostfixIdx;
    }
  }
  std::string qqq(b, b + res.first);
  if (res.second >= 0) qqq.insert(qqq.end(), b + blen - res.second, b + blen);
  if (qqq.length())
    std::cout << qqq;
  else
    std::cout << '-';
  return 0;
}
