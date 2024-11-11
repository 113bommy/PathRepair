#include <bits/stdc++.h>
using namespace std;
long long n, x, r[2005], l, sum, tmp, sz;
string s, t[2005], q, answer = "0";
bitset<2005> b;
vector<long long> v[2005], ans;
multiset<pair<long long, long long> > ms;
multiset<pair<long long, long long> >::iterator it;
pair<long long, long long> p;
bool f;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  t[0] = "1";
  for (int i = 1; i <= 2000; i++) {
    sum = 0;
    for (int j = t[i - 1].size() - 1; j >= 0; j--) {
      tmp = (t[i - 1][j] - '0') * 2 + sum;
      if (tmp >= 10) {
        tmp -= 10;
        sum = 1;
      } else {
        sum = 0;
      }
      t[i] = (char)(tmp + '0') + t[i];
    }
    if (sum) {
      t[i] = '1' + t[i];
    }
  }
  for (int i = 1; i <= n; i++) {
    cin >> s >> x;
    if (s == "sell") {
      b[x] = true;
      r[x] = i;
    } else if (s == "win" && !b[x]) {
      v[x].push_back(i);
    }
  }
  ms.insert(make_pair(1, n));
  for (int i = 2000; i >= 0; i--) {
    if (v[i].size() && r[i]) {
      l = v[i].back(), f = false;
      for (it = ms.begin(); it != ms.end(); it++) {
        p = *it;
        if (p.first <= l && r[i] <= p.second) {
          f = true;
          break;
        }
      }
      if (f) {
        ms.erase(p);
        ans.push_back(i);
        if (l != p.first && p.first < l - 1) {
          ms.insert(make_pair(p.first, l - 1));
        }
        if (r[i] != p.second && p.second > r[i] + 1) {
          ms.insert(make_pair(r[i] + 1, p.second));
        }
      }
    }
  }
  sort(ans.begin(), ans.end(), greater<long long>());
  for (int i = 0; i < ans.size(); i++) {
    x = ans[i];
    if (!i) {
      answer = t[x];
    } else {
      sz = answer.size() - 1, sum = 0;
      for (int j = t[x].size() - 1; j >= 0; j--) {
        tmp = (t[x][j] - '0') + (answer[sz] - '0') + sum;
        if (tmp >= 10) {
          tmp -= 10;
          sum = 1;
        } else {
          sum = 0;
        }
        answer[sz] = (tmp + '0');
        sz--;
      }
      if (sum) {
        while (answer[sz] == '9' && sz >= 0) {
          answer[sz] = 0;
          sz--;
        }
        if (sz == -1) {
          answer = '1' + answer;
        } else {
          answer[sz]++;
        }
      }
    }
  }
  cout << answer << '\n';
}
