#include <bits/stdc++.h>
using namespace std;
int cnt[10];
int len(int first) {
  int ret = 0;
  while (first > 0) {
    first /= 10;
    ret++;
  }
  return ret;
}
int min_pos(int first) {
  for (int i = (first); i < int(10); i++) {
    if (cnt[i]) {
      return i;
    }
  }
  return -1;
}
string go(string q, bool f = true) {
  bool q_printed = false, first = f;
  int t;
  string ret = "";
  while (!q_printed) {
    string k = "";
    if ((t = min_pos(first)) == q[int((k).size())] - '0') {
      k.push_back(t + '0');
      first = false;
      cnt[t]--;
      if (t == min_pos(first)) {
        while (int((k).size()) < int((q).size()) && cnt[t] > 0 &&
               t == q[int((k).size())] - '0') {
          k.push_back(t + '0');
          cnt[t]--;
        }
      }
    }
    if (t == -1) {
      ret += min(k + q, q + k);
      q_printed = true;
    } else {
      if (q == k) {
        ret += q + k;
        q_printed = true;
      } else {
        if ((t = min_pos(first)) > q[int((k).size())] - '0') {
          ret += min(k + q, q + k);
          q_printed = true;
        } else {
          ret += k;
          if (int((k).size()) == 0) {
            ret.push_back(t + '0');
            cnt[t]--;
          }
        }
      }
    }
    first = false;
  }
  while ((t = min_pos(0)) != -1) {
    ret += string(cnt[t], '0' + t);
    cnt[t] = 0;
  }
  return ret;
}
int main() {
  std::ios_base::sync_with_stdio(false);
  string p, q;
  cin >> p >> q;
  sort((p).begin(), (p).end());
  if (p == "01") {
    cout << 0;
    return 0;
  }
  for (auto c : (p)) {
    cnt[c - '0']++;
  }
  for (auto c : (q)) {
    cnt[c - '0']--;
  }
  int l = -1;
  for (int first = (1); first < int(int((p).size()) + 1); first++) {
    if (len(first) + first == int((p).size())) {
      l = first;
      break;
    }
  }
  while (l > 0) {
    cnt[l % 10]--;
    l /= 10;
  }
  if (q[0] != '0') {
    string f = q;
    for (int i = 0; i < int(10); i++) {
      f += string(cnt[i], i + '0');
    }
    string t = go(q);
    cout << min(f, t);
  } else {
    int t = min_pos(1);
    cnt[t]--;
    cout << t;
    cout << go(q, false);
  }
  return 0;
}
