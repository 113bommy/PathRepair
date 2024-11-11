#include <bits/stdc++.h>
using namespace std;
const int N = 100004;
pair<int, int> arr[N];
set<pair<int, int> > st;
set<int> sid;
int a[N];
int main() {
  int n;
  scanf("%d", &n);
  int i;
  for (i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    arr[i] = make_pair(a[i], i);
  }
  if (n == 1) {
    printf("%d\n", a[1] + 1);
    return 0;
  }
  sort(arr + 1, arr + n + 1);
  reverse(arr + 1, arr + n + 1);
  if (n - arr[1].second == arr[1].second - 1) {
    st.insert(make_pair(arr[1].second - 1, 2));
  } else {
    if (arr[1].second != 1) st.insert(make_pair(arr[1].second - 1, 1));
    if (arr[1].second != n) st.insert(make_pair(n - arr[1].second, 1));
  }
  sid.insert(arr[1].second);
  int ans, mx;
  if (st.size() == 1) {
    ans = arr[2].first + 1;
    if (arr[1].second != 1 && arr[1].second != n)
      mx = 2;
    else
      mx = 1;
  } else {
    ans = arr[n].first + 1;
    mx = 0;
  }
  for (i = 2; i < n; i++) {
    set<int>::iterator sit;
    sit = sid.lower_bound(arr[i].second);
    set<int>::reverse_iterator rit;
    int id1 = 0, id2 = n + 1;
    if (sit == sid.end()) {
      rit = sid.rbegin();
      id1 = *rit;
    } else {
      id2 = *sit;
      if (sit != sid.begin()) {
        sit--;
        id1 = *sit;
      }
    }
    sid.insert(arr[i].second);
    int val1 = arr[i].second - id1 - 1;
    int val2 = id2 - arr[i].second - 1;
    int val = id2 - id1 - 1;
    set<pair<int, int> >::iterator it1;
    it1 = st.lower_bound(make_pair(val, -1));
    pair<int, int> p1 = *it1;
    if (it1->second == 1)
      st.erase(make_pair(p1.first, p1.second));
    else {
      st.erase(make_pair(p1.first, p1.second));
      st.insert(make_pair(p1.first, p1.second - 1));
    }
    if (val1 != 0) {
      it1 = st.lower_bound(make_pair(val1, -1));
      if (it1 == st.end() || it1->first > val1) {
        st.insert(make_pair(val1, 1));
      } else {
        p1 = *it1;
        st.erase(make_pair(val1, p1.second));
        st.insert(make_pair(val1, p1.second + 1));
      }
    }
    if (val2 != 0) {
      it1 = st.lower_bound(make_pair(val2, -1));
      if (it1 == st.end() || it1->first > val2) {
        st.insert(make_pair(val2, 1));
      } else {
        p1 = *it1;
        st.erase(make_pair(val2, p1.second));
        st.insert(make_pair(val2, p1.second + 1));
      }
    }
    if (st.size() <= 1) {
      if ((st.begin())->second >= mx) {
        ans = arr[i + 1].first + 1;
        mx = (st.begin())->second;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
