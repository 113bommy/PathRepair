#include <bits/stdc++.h>
using namespace std;
struct nPair {
  int num;
  int idx;
};
int main(int argc, char **argv) {
  int len;
  int flag[100000] = {0};
  nPair origin[100000];
  list<list<int>> subseqs;
  list<int> subseq;
  scanf("%d", &len);
  for (int i = 0; i < len; i++) {
    scanf("%d", &origin[i].num);
    origin[i].idx = i + 1;
  }
  sort(origin, origin + len,
       [](nPair a, nPair b) -> bool { return a.num < b.num; });
  for (int i = 0; i < len; i++) {
    origin[i].num = i + 1;
  }
  sort(origin, origin + len,
       [](nPair a, nPair b) -> bool { return a.idx < b.idx; });
  for (int i = 0; i < len; i++) {
    if (flag[i]) {
      continue;
    }
    subseq.clear();
    int head = origin[i].num;
    do {
      subseq.push_back(origin[i].idx);
      flag[i] = 1;
      i = origin[i].num - 1;
    } while (origin[i].num != head);
    subseqs.push_back(subseq);
  }
  printf("%d\n", subseqs.size());
  for (auto i = subseqs.begin(); i != subseqs.end(); i++) {
    subseq = *i;
    printf("%d ", subseq.size());
    for (auto j = subseq.begin(); j != subseq.end(); j++) {
      printf("%d ", *j);
    }
    cout << endl;
  }
  return 0;
}
