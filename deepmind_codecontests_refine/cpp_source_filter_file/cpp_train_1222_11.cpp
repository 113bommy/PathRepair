#include <bits/stdc++.h>
using namespace std;
void read(int &sz, pair<int, int> *a) {
  for (int i = 0; i < sz; i++) {
    scanf("%d %d", &a[i].first, &a[i].second);
    if (a[i].first > a[i].second) {
      swap(a[i].first, a[i].second);
    }
  }
}
int share(pair<int, int> a, pair<int, int> b) {
  if (a == b) {
    return -1;
  }
  set<int> st;
  for (int i : {a.first, a.second, b.first, b.second}) {
    if (st.count(i)) {
      return i;
    }
    st.insert(i);
  }
  return -1;
}
int N, M;
pair<int, int> A[12], B[12];
set<int> aset[12], bset[12];
int main() {
  scanf("%d %d", &N, &M);
  read(N, A);
  read(M, B);
  set<int> ans;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      int s = share(A[i], B[j]);
      if (s != -1) {
        ans.insert(s);
        aset[i].insert(s);
        bset[j].insert(s);
      }
    }
  }
  if (ans.size() == 1) {
    printf("%d\n", *ans.begin());
    return 0;
  }
  bool know = true;
  for (int i = 0; i < N; i++) {
    know &= (aset[i].size() == 1);
  }
  for (int i = 0; i < M; i++) {
    know &= (bset[i].size() == 1);
  }
  puts(know ? "0" : "-1");
}
