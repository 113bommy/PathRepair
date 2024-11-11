#include <bits/stdc++.h>
using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");
int n, k;
vector<int> simple = {2,   3,   5,   7,   11,  13,  17,  19,  23,  29,  31,
                      37,  41,  43,  47,  53,  59,  61,  67,  71,  73,  79,
                      83,  89,  97,  101, 103, 107, 109, 113, 127, 131, 137,
                      139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193,
                      197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257,
                      263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317};
pair<list<pair<int, int>>, list<pair<int, int>>> divs(int a) {
  list<pair<int, int>> is, need;
  int left = a;
  for (int div : simple) {
    int cur_cnt = 0;
    while (left % div == 0) {
      cur_cnt++;
      left /= div;
    }
    cur_cnt %= k;
    if (cur_cnt != 0) {
      is.push_back({div, cur_cnt});
      need.push_back({div, k - cur_cnt});
    }
  }
  if (left > 1) {
    is.push_back({left, 1});
    need.push_back({left, k - 1});
  }
  return {is, need};
}
int main() {
  in.tie(0);
  out.tie(0);
  in.sync_with_stdio(0);
  out.sync_with_stdio(0);
  ;
  in >> n >> k;
  map<list<pair<int, int>>, int> mp;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    int a;
    in >> a;
    pair<list<pair<int, int>>, list<pair<int, int>>> cur = divs(a);
    ans += mp[cur.second];
    mp[cur.first]++;
  }
  out << ans;
}
