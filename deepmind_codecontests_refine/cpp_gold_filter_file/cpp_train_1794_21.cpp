#include <bits/stdc++.h>
using namespace std;
vector<vector<long>> input;
long n, m;
vector<long> makebool(long mid) {
  map<long, long> mp;
  vector<long> boolans;
  for (long i = 0; i < n; ++i) {
    long numbool = 0;
    for (long j = 0; j < m; ++j) {
      numbool = numbool << 1;
      if (mid <= input[i][j]) {
        numbool |= 1;
      }
    }
    if (mp[numbool] == 0) {
      mp[numbool] = 1;
      boolans.push_back(numbool);
    }
  }
  return boolans;
}
int checkbool(vector<long> &boolans) {
  long lim = (1 << m) - 1;
  long size = boolans.size();
  for (long i = 0; i < size; ++i) {
    for (long j = i; j < size; j++) {
      long res = boolans[i] | boolans[j];
      if (res == lim) {
        return 1;
      }
    }
  }
  return 0;
}
void printans(long mid) {
  map<long, long> mp;
  vector<long> boolans;
  for (long i = 0; i < n; ++i) {
    long numbool = 0;
    for (long j = 0; j < m; ++j) {
      numbool = numbool << 1;
      if (mid <= input[i][j]) {
        numbool |= 1;
      }
    }
    if (mp[numbool] == 0) {
      mp[numbool] = i;
      boolans.push_back(numbool);
    }
  }
  long lim = (1 << m) - 1;
  long size = boolans.size();
  for (long i = 0; i < size; ++i) {
    for (long j = i; j < size; j++) {
      long res = boolans[i] | boolans[j];
      if (res == lim) {
        cout << mp[boolans[i]] + 1 << " " << mp[boolans[j]] + 1 << endl;
        return;
      }
    }
  }
}
int main() {
  cin >> n >> m;
  input.resize(n, vector<long>(m));
  for (long i = 0; i < n; ++i) {
    for (long j = 0; j < m; ++j) {
      cin >> input[i][j];
    }
  }
  long low = 0, high = 1000000000;
  while (low < high) {
    long mid = (high + low) / 2 + 1;
    vector<long> boolans = makebool(mid);
    int chk = checkbool(boolans);
    if (chk) {
      low = mid;
    } else {
      high = mid - 1;
    }
  }
  vector<long> temp = makebool(low);
  if (!checkbool(temp)) {
    return 0;
  }
  printans(low);
  return 0;
}
