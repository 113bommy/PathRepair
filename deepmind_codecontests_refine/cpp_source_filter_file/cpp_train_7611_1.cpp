#include <bits/stdc++.h>
using i64 = long long;
bool suba(char *s, char *a, char *temp, std::set<char> &remain, int i) {
  for (int len = strlen(s); i < len; i++) {
    if (temp[s[i] - 'a']) {
      if (temp[s[i] - 'a'] > a[i]) return true;
      if (temp[s[i] - 'a'] != a[i]) return false;
    } else {
      auto it = remain.lower_bound(a[i]);
      if (it == remain.end()) return false;
      if (*it != a[i]) {
        temp[s[i] - 'a'] = *it;
        remain.erase(it);
        return true;
      } else {
        it++;
        if (it != remain.end()) {
          temp[s[i] - 'a'] = *it;
          remain.erase(it);
          return true;
        }
        temp[s[i] - 'a'] = a[i];
        remain.erase(a[i]);
      }
    }
  }
  return true;
}
bool subb(char *s, char *b, char *temp, std::set<char> &remain, int i) {
  for (int len = strlen(s); i < len; i++) {
    if (temp[s[i] - 'a']) {
      if (temp[s[i] - 'a'] < b[i]) return true;
      if (temp[s[i] - 'a'] != b[i]) return false;
    } else {
      auto it = remain.begin();
      if (*it > b[i]) return false;
      if (*it < b[i]) {
        temp[s[i] - 'a'] = *it;
        remain.erase(it);
        return true;
      } else {
        temp[s[i] - 'a'] = b[i];
        remain.erase(it);
      }
    }
  }
  return true;
}
int main() {
  int t;
  scanf("%d", &t);
  int k;
  char s[1000010], a[1000010], b[1000010];
  while (t--) {
    scanf("%d%s%s%s", &k, s, a, b);
    int len = strlen(s);
    char temp[27]{}, cptemp[27]{};
    std::set<char> remain, cpremain;
    for (int i = 0; i < k; i++) remain.insert('a' + i);
    for (int i = 0; i < len; i++) {
      if (a[i] == b[i]) {
        if (!temp[s[i] - 'a']) {
          auto it = remain.find(a[i]);
          if (it == remain.end()) goto err;
          temp[s[i] - 'a'] = a[i];
          remain.erase(it);
        } else if (temp[s[i] - 'a'] != a[i])
          goto err;
      } else {
        if (temp[s[i] - 'a']) {
          auto c = temp[s[i] - 'a'];
          if (c < a[i] || b[i] < c) goto err;
          if (a[i] < c && c < b[i]) break;
          if (c == a[i]) {
            if (suba(s, a, temp, remain, ++i)) break;
          } else {
            if (subb(s, b, temp, remain, ++i)) break;
          }
          goto err;
        } else {
          std::set<char> cand;
          for (auto it = remain.lower_bound(a[i]);
               it != remain.end() && *it <= b[i]; it++) {
            cand.insert(*it);
          }
          if (cand.empty()) goto err;
          auto it = cand.upper_bound(a[i]);
          if (it != cand.end() && *it < b[i]) {
            temp[s[i] - 'a'] = *it;
            remain.erase(it);
            break;
          }
          if (remain.find(a[i]) != remain.end() &&
              remain.find(b[i]) != remain.end()) {
            cpremain = remain;
            for (int i = 0; i < 27; i++) cptemp[i] = temp[i];
            temp[s[i] - 'a'] = a[i];
            cptemp[s[i] - 'a'] = b[i];
            remain.erase(a[i]);
            cpremain.erase(b[i]);
            i++;
            if (suba(s, a, temp, remain, i)) break;
            std::swap(temp, cptemp);
            std::swap(remain, cpremain);
            if (subb(s, b, temp, remain, i)) break;
            goto err;
          } else if (remain.find(a[i]) != remain.end()) {
            temp[s[i] - 'a'] = a[i];
            remain.erase(a[i]);
            i++;
            if (suba(s, a, temp, remain, i)) break;
            goto err;
          } else if (remain.find(b[i]) != remain.end()) {
            temp[s[i] - 'a'] = b[i];
            remain.erase(b[i]);
            i++;
            if (subb(s, b, temp, remain, i)) break;
            goto err;
          } else
            goto err;
        }
      }
    }
    for (int i = 0; i < k; i++) {
      if (temp[i]) continue;
      temp[i] = *remain.begin();
      remain.erase(remain.begin());
    }
    printf("YES\n%s\n", temp);
    continue;
  err:
    printf("NO\n");
  }
  return 0;
}
