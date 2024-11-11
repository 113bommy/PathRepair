#include <bits/stdc++.h>
using namespace std;
const long long int first = 204761410463LL;
void out(vector<long long int>& v) {
  sort(v.begin(), v.end());
  v.resize(unique(v.begin(), v.end()) - v.begin());
  while (v.back() > 10004205361450474LL) v.pop_back();
  printf("%ld", v.size());
  for (long long int i : v) printf(" %lld", i);
  printf("\n");
  fflush(stdout);
}
int main() {
  long long int l = 1, r = 10004205361450474LL, nxt, now;
  int temp;
  vector<long long int> v;
  v.push_back(first);
  out(v);
  scanf("%d", &temp);
  if (temp < 0) return 0;
  if (temp == 0) {
    v.clear();
    v.push_back(2046);
    out(v);
    scanf("%d", &temp);
    if (temp < 0)
      return 0;
    else if (temp == 0) {
      v.clear();
      v.push_back(6);
      out(v);
      scanf("%d", &temp);
      if (temp < 0)
        return 0;
      else if (temp == 0) {
        v.clear();
        v.push_back(2);
        out(v);
        scanf("%d", &temp);
        if (temp < 0)
          return 0;
        else if (temp == 0) {
          printf("1 1\n");
          return 0;
        } else {
          printf("3 3 4 5\n");
          return 0;
        }
      } else {
        v.clear();
        l = 7;
        nxt = l - 1;
        for (int i = 0; i < 7; i++) {
          nxt += nxt + 2;
          v.push_back(nxt);
        }
        out(v);
        scanf("%d", &temp);
        if (temp < 0)
          return 0;
        else {
          if (temp > 0) l = v[temp - 1] + 1;
          v.clear();
          for (int i = 0; i < l; i++) v.push_back(l + i);
          out(v);
          return 0;
        }
      }
    } else {
      v.clear();
      l = 2047;
      nxt = 20468427;
      now = 2047;
      v.push_back(nxt);
      for (int i = 1; i < l; i++) {
        nxt += 100020001;
        v.push_back(nxt);
      }
      out(v);
      scanf("%d", &temp);
      if (temp < 0)
        return 0;
      else if (temp == 0) {
        v.clear();
        nxt = l - 1;
        for (int i = 0; i < now; i++) {
          nxt += min(nxt, 9999LL) + 2;
          v.push_back(nxt);
        }
        out(v);
        scanf("%d", &temp);
        if (temp < 0)
          return 0;
        else {
          if (temp > 0) l = v[temp - 1] + 1;
          v.clear();
          now = min(l, 10000LL);
          for (int i = 0; i < now; i++) v.push_back(l + i);
          out(v);
          return 0;
        }
      } else {
        l = v[temp - 1] + 1;
        now = min(l, 10000LL);
        v.clear();
        nxt = l - 1;
        for (int i = 0; i < now; i++) {
          nxt += 10001;
          v.push_back(nxt);
        }
        out(v);
        scanf("%d", &temp);
        if (temp < 0)
          return 0;
        else {
          if (temp > 0) l = v[temp - 1] + 1;
          v.clear();
          now = min(l, 10000LL);
          v.clear();
          for (int i = 0; i < now; i++) v.push_back(l + i);
          out(v);
          return 0;
        }
      }
    }
  } else {
    v.clear();
    l = first;
    now = 10000;
    nxt = l - 1;
    for (int i = 0; i < now; i++) {
      nxt += 1000300030001LL;
      v.push_back(nxt);
    }
    out(v);
    scanf("%d", &temp);
    if (temp < 0)
      return 0;
    else {
      if (temp > 0) l = v[temp - 1] + 1;
      v.clear();
      nxt = l - 1;
      for (int i = 0; i < now; i++) {
        nxt += 100020001LL;
        v.push_back(nxt);
      }
      out(v);
      scanf("%d", &temp);
      if (temp < 0)
        return 0;
      else {
        if (temp > 0) l = v[temp - 1] + 1;
        v.clear();
        nxt = l - 1;
        for (int i = 0; i < now; i++) {
          nxt += 10001LL;
          v.push_back(nxt);
        }
        out(v);
        scanf("%d", &temp);
        if (temp < 0)
          return 0;
        else {
          if (temp > 0) l = v[temp - 1] + 1;
          v.clear();
          for (int i = 0; i < now; i++) v.push_back(l + i);
          out(v);
          return 0;
        }
      }
    }
  }
}
