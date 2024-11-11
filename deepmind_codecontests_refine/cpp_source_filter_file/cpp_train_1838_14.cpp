#include <bits/stdc++.h>
using namespace std;
vector<long long> razl(long long p, long long k) {
  vector<long long> a;
  while (p > 0) {
    a.push_back(p % k);
    p /= k;
  }
  return a;
}
void priv1(vector<long long>& razl, long long k) {
  for (int i = 0; i < razl.size(); ++i) {
    if (i % 2 == 1) {
      if (razl[i] != 0) {
        if (i + 1 != razl.size()) {
          razl[i + 1]++;
          razl[i] = razl[i] - k;
        } else {
          razl.push_back(1);
          razl[i] = razl[i] - k;
        }
      }
    }
  }
}
bool check(vector<long long>& razl, long long k) {
  for (int i = 0; i < razl.size(); ++i) {
    if (razl[i] >= k || razl[i] <= -k) {
      return true;
    }
  }
  return false;
}
bool secondCheck(vector<long long>& razl, long long k) {
  for (int i = 0; i < razl.size(); ++i) {
    if (i % 2 == 0) {
      if (razl[i] < 0) {
        return true;
      }
    } else {
      if (razl[i] > 0) {
        return true;
      }
    }
  }
  return false;
}
vector<long long> priv2(vector<long long>& razl, long long k) {
  while (check(razl, k)) {
    for (int i = 0; i < razl.size(); ++i) {
      if (i % 2 == 0) {
        if (razl[i] >= k) {
          if (i != razl.size()) {
            razl[i + 1]++;
            razl[i] -= k;
          } else {
            razl.push_back(1);
            razl[i] -= k;
          }
        }
      } else {
        if (razl[i] <= -k) {
          if (i != razl.size()) {
            razl[i + 1]--;
            razl[i] += k;
          } else {
            razl.push_back(-1);
            razl[i] += k;
          }
        }
      }
    }
    if (secondCheck(razl, k)) {
      priv1(razl, k);
    }
  }
  return razl;
}
int main() {
  long long p, k;
  cin >> p >> k;
  vector<long long> a = razl(p, k);
  priv1(a, k);
  priv2(a, k);
  while (a.back() == 0) {
    a.pop_back();
  }
  cout << a.size() << endl;
  for (int i = 0; i < a.size(); ++i) {
    if (i % 2 == 0) {
      cout << a[i] << ' ';
    } else {
      cout << -a[i] << ' ';
    }
  }
  return 0;
}
