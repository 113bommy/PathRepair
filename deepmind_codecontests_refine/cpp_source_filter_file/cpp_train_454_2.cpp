#include <bits/stdc++.h>
using namespace std;
void cout_v(vector<int>& a) {
  long long n = a.size();
  for (long long i = 0; i < n; i++) {
    cout << a[i] << " ";
    if (i != n - 1) {
      continue;
    } else
      cout << endl;
  }
}
void cin_v(vector<long long>& a) {
  long long n = a.size();
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
}
long long factorial(long long n) {
  long long c;
  long long result = 1;
  for (c = 1; c <= n; c++) result = result * c;
  return result;
}
long long pow_mod(long long a, long long b, long long m) {
  long long res = 1;
  while (b > 0) {
    if (b % 2 == 1) res = (res * a) % m;
    b = b / 2;
    a = (a * a) % m;
  }
  return res;
}
long long inv = 0;
void merge(vector<int>& a, int low, int mid, int high) {
  int temp[100005];
  int i = low;
  int j = mid + 1;
  int k = low;
  while ((i <= mid) && (j <= high)) {
    if (a[i] <= a[j]) {
      inv += (high - j + 1);
      temp[k++] = a[i++];
    } else {
      temp[k++] = a[j++];
    }
  }
  while (i <= mid) temp[k++] = a[i++];
  while (j <= high) temp[k++] = a[j++];
  for (i = low; i <= high; i++) a[i] = temp[i];
}
void merge_sort(vector<int>& a, int low, int high) {
  int mid;
  if (low != high) {
    mid = (low + high) / 2;
    merge_sort(a, low, mid);
    merge_sort(a, mid + 1, high);
    merge(a, low, mid, high);
  }
}
long long InverseEuler(long long n, long long m) {
  return pow_mod(n, m - 2, m);
}
const int mod = 1000000007;
typedef struct ele {
  int v1, v2;
} ele;
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  stack<ele> s;
  int maxa = 0;
  for (int i = 0; i < n; i++) {
    if (s.empty()) {
      s.push({a[i], 0});
    } else {
      ele temp = s.top();
      if (a[i] < temp.v1) {
        int sc = 1;
        maxa = max(maxa, sc);
        s.push({a[i], sc});
      } else {
        ele v = s.top();
        int pr = v.v2;
        while (!s.empty() && v.v1 < a[i]) {
          s.pop();
          if (s.empty()) break;
          pr = v.v2;
          v = s.top();
        }
        if (s.empty()) {
          s.push({a[i], 0});
        } else {
          s.push({a[i], pr + 1});
          maxa = max(maxa, pr + 1);
        }
      }
    }
  }
  cout << maxa << endl;
}
