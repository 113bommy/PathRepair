#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e14 + 9;
long long k;
multiset<long long> pos, neg, meno;
long long spos = 0, sneg = 0, smen = 0;
void insert(long long num) {
  if (num > 0) {
    if ((long long)(pos).size() < k) {
      pos.insert(num);
      spos += num;
    } else if ((long long)(pos).size() > 0 && num > *pos.begin()) {
      spos += num - *pos.begin();
      smen += *pos.begin();
      meno.insert(*pos.begin());
      pos.erase(pos.begin());
      pos.insert(num);
    } else {
      smen += num;
      meno.insert(num);
    }
  } else {
    if ((long long)(neg).size() < k) {
      sneg += num;
      neg.insert(num);
    } else if ((long long)(neg).size() > 0 && num < *neg.rbegin()) {
      sneg += num - *neg.rbegin();
      smen += *neg.rbegin();
      meno.insert(*neg.rbegin());
      neg.erase(neg.find(*neg.rbegin()));
      neg.insert(num);
    } else {
      smen += num;
      meno.insert(num);
    }
  }
}
void erase(long long num) {
  if (meno.find(num) != meno.end()) {
    smen -= num;
    meno.erase(meno.find(num));
  } else if (pos.find(num) != pos.end()) {
    spos -= num;
    pos.erase(pos.find(num));
    if ((long long)(meno).size() > 0 && *meno.rbegin() > 0) {
      spos += *meno.rbegin();
      smen -= *meno.rbegin();
      pos.insert(*meno.rbegin());
      meno.erase(meno.find(*meno.rbegin()));
    }
  } else {
    sneg -= num;
    neg.erase(neg.find(num));
    if ((long long)(meno).size() > 0 && *meno.begin() < 0) {
      sneg += *meno.begin();
      smen -= *meno.begin();
      pos.insert(*meno.begin());
      meno.erase(meno.begin());
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n, len;
  cin >> n >> len;
  long long vet[n + 2];
  for (long long i = 0; i < (n); ++i) {
    cin >> vet[i];
  }
  cin >> k;
  for (long long i = 0; i < (len); ++i) {
    insert(vet[i]);
  }
  long long ans = max(spos + abs(sneg) + smen, abs(-spos + sneg + smen));
  for (long long i = len; i < (n); ++i) {
    if (vet[i - len] != 0) erase(vet[i - len]);
    if (vet[i] != 0) insert(vet[i]);
    ans = max({ans, spos + abs(sneg) + smen, abs(-spos + sneg + smen)});
  }
  cout << ans << "\n";
  return 0;
}
