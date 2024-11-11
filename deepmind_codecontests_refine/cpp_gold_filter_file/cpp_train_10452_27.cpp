#include <bits/stdc++.h>
using namespace std;
struct order {
  long long a, b;
  int num;
};
int n, p, k;
vector<order> arr;
set<pair<pair<long long, long long>, int> > st;
bool cmp(const order &a, const order &b) {
  return (a.b == b.b) ? a.a > b.a : a.b < b.b;
}
int main(int argc, char *argv[]) {
  scanf("%d%d%d", &n, &p, &k);
  arr.resize(n);
  for (int i = 0; i < n; ++i) {
    arr[i].num = i + 1;
    scanf("%lld%lld", &arr[i].a, &arr[i].b);
  }
  sort(arr.begin(), arr.end(), cmp);
  int fn = n - 1;
  for (int i = n - 1; i >= p - k; --i) {
    if (st.size() < k) {
      st.insert(make_pair(make_pair(arr[i].a, arr[i].b), arr[i].num));
      fn = i;
    } else {
      if (st.begin()->first < make_pair(arr[i].a, arr[i].b)) {
        st.erase(st.begin());
        st.insert(make_pair(make_pair(arr[i].a, arr[i].b), arr[i].num));
        fn = i;
      }
    }
  }
  for (set<pair<pair<long long, long long>, int> >::iterator it = st.begin();
       it != st.end(); ++it) {
    printf("%d ", it->second);
  }
  int u = k;
  for (int i = fn - 1; u < p; --i, ++u) {
    printf("%d ", arr[i].num);
  }
  return 0;
}
