#include <bits/stdc++.h>
using namespace std;
struct Sqrt {
  Sqrt(string& rhs) : data(rhs) {
    s = sqrt(rhs.size());
    block_unique_chars.resize(ceil((float)rhs.size() / s));
    for (int i = 0; i < block_unique_chars.size(); ++i) {
      for (int j = i * s; j < min((i + 1) * s, (int)data.size()); ++j) {
        ++block_unique_chars[i][rhs[j] - 'a'];
      }
    }
  }
  void Set(int pos, char c) {
    int block_num = pos / s;
    block_unique_chars[block_num][data[pos] - 'a']--;
    data[pos] = c;
    block_unique_chars[block_num][data[pos] - 'a']++;
  }
  int Min(int l, int r) const {
    int res[26]{0};
    int start = l / s, end = r / s;
    if (start == end) {
      for (int i = l; i < r; ++i) {
        ++res[data[i] - 'a'];
      }
    } else {
      for (int i = l, e = (start + 1) * s; i < e; ++i) {
        ++res[data[i] - 'a'];
      }
      for (int i = start + 1; i < end; ++i) {
        for (int j = 0; j < 26; ++j) {
          res[j] += block_unique_chars[i][j];
        }
      }
      for (int i = end * s; i <= r; ++i) {
        ++res[data[i] - 'a'];
      }
    }
    int ans = 0;
    for (int i = 0; i < 26; ++i) ans += (int)(res[i] > 0);
    return ans;
  }
  string& data;
  int s;
  vector<array<int, 26>> block_unique_chars;
};
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  string s;
  cin >> s;
  int q;
  cin >> q;
  Sqrt ds(s);
  for (int i = 0; i < q; ++i) {
    int cmd;
    cin >> cmd;
    if (cmd == 1) {
      int pos;
      char c;
      cin >> pos >> c;
      --pos;
      ds.Set(pos, c);
    } else {
      int l, r;
      cin >> l >> r;
      --l, --r;
      cout << ds.Min(l, r) << '\n';
    }
  }
  return 0;
}
