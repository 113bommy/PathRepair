#include <bits/stdc++.h>
using namespace std;
long long SZ = 1000000000000000000LL;
map<long long, map<long long, long long>> mem;
map<long long, long long> go(long long i, long long j) {
  map<long long, long long> D;
  if (i + 1 == j) return D;
  if (mem[j - i].size() != 0) return mem[j - i];
  long long m = (i + j) / 2;
  long long d = min(j - m, m - i);
  D[d]++;
  map<long long, long long> A = go(i, m);
  map<long long, long long> B = go(m, j);
  for (const pair<long long, long long> &p : A) {
    D[p.first] += p.second;
  }
  for (const pair<long long, long long> &p : B) {
    D[p.first] += p.second;
  }
  return mem[j - i] = D;
}
void recurse(long long i, long long j, long long K, long long pp = 0) {
  long long m = (i + j) / 2;
  long long d = min(m - i, j - m);
  map<long long, long long> D;
  map<long long, long long> A = go(i, m);
  map<long long, long long> B = go(m, j);
  for (const pair<long long, long long> &p : A) {
    D[-p.first] += p.second;
  }
  for (const pair<long long, long long> &p : B) {
    D[-p.first] += p.second;
  }
  D[-d]++;
  for (pair<long long, long long> p : D) {
    if (-p.first != pp) continue;
    if (A.count(-p.first)) {
      if (A[-p.first] >= K) {
        recurse(i, m, K, -p.first);
        return;
      } else {
        K -= A[-p.first];
      }
    }
    if (-p.first == d) {
      if (K == 1) {
        cout << m + 1 << endl;
        return;
      } else {
        K--;
      }
    }
    if (B.count(-p.first)) {
      if (B[-p.first] >= K) {
        recurse(m, j, K, -p.first);
        return;
      } else {
        K -= B[-p.first];
      }
    }
  }
}
int main() {
  long long K;
  cin >> SZ >> K;
  if (K == 1) {
    cout << 1 << endl;
    return 0;
  }
  if (K == 2) {
    cout << SZ << endl;
    return 0;
  }
  K -= 2;
  map<long long, long long> D = go(0, SZ - 1);
  long long pp = 0;
  for (map<long long, long long>::reverse_iterator it = D.rbegin();
       it != D.rend(); ++it) {
    if (it->second >= K) {
      pp = it->first;
      break;
    } else {
      K -= it->second;
    }
  }
  recurse(0, SZ - 1, K, pp);
}
