#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k;
  cin >> n >> k;
  long long aux = n;
  vector<long long> v;
  if (n == k) {
    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
      cout << "1 ";
    }
    return 0;
  }
  if (n % 2 != 0) {
    n--;
    k--;
    aux--;
    long long j = 0;
    while (n != 0) {
      for (int i = 0; i < 100; i++) {
        if (pow(2, i) > n) {
          j = i;
          break;
        }
      }
      j = j - 1;
      v.push_back(pow(2, j));
      n = n - pow(2, j);
    }
    if (k < v.size() || k > aux) {
      cout << "NO";
      return 0;
    } else {
      cout << "YES" << endl;
      long long div = k - v.size();
      long long p = 0;
      for (int i = 0; i < div; i++) {
        if (v[p] >= 2) {
          v.push_back(v[p] / 2);
          v[p] = v[p] / 2;
        } else {
          p++;
          i--;
        }
      }
      v.push_back(1);
      sort(v.begin(), v.end());
      for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
      }
    }
  } else {
    long long j = 0;
    while (n != 0) {
      for (int i = 0; i < 100; i++) {
        if (pow(2, i) > n) {
          j = i;
          break;
        }
      }
      j = j - 1;
      v.push_back(pow(2, j));
      n = n - pow(2, j);
    }
    if (k < v.size() || k > aux) {
      cout << "NO";
      return 0;
    } else {
      cout << "YES" << endl;
      long long div = k - v.size();
      long long p = 0;
      for (int i = 0; i < div; i++) {
        if (v[p] >= 2) {
          v.push_back(v[p] / 2);
          v[p] = v[p] / 2;
        } else {
          p++;
          i--;
        }
      }
      sort(v.begin(), v.end());
      for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
      }
    }
  }
}
