#include <bits/stdc++.h>
using namespace std;
void merge(long long arr[], long long l, long long m, long long r) {
  long long i, j, k;
  long long n1 = m - l + 1;
  long long n2 = r - m;
  long long L[n1], R[n2];
  for (i = 0; i < n1; i++) L[i] = arr[l + i];
  for (j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
  i = 0;
  j = 0;
  k = l;
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }
  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
  }
}
void mergeSort(long long arr[], long long l, long long r) {
  if (l < r) {
    long long m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
  }
}
int isPrime(long long k) {
  if (k <= 1) {
    return 0;
  }
  if (k == 2) {
    return 1;
  }
  if (k % 2 == 0) {
    return 0;
  }
  long long i = 3;
  while (i * i <= k) {
    if (k % i == 0) {
      return 0;
    }
    i += 2;
  }
  return 1;
}
long long gcd(long long k, long long l) {
  if (l == 0) {
    return k;
  }
  if (k == 0) {
    return l;
  }
  if (k > l) {
    return gcd(l, k % l);
  } else {
    return gcd(l % k, k);
  }
}
long long duo(long long n, long long k) {
  long long h, max = 1;
  if (k >= 100) {
    h = (n * 100) / k;
    while (h % 10 != 9) {
      h--;
    }
    if ((h % 10) * (h / 10) > (n % 10) * (n / 10)) {
      max = n;
    } else {
      return duo(n % (k / 100), k / 100);
    }
  } else {
  }
  return max;
}
int main(int argc, const char* argv[]) {
  long long n, k, m, s = 0, t = 0;
  cin >> n >> k >> m;
  vector<long long> v[n + m];
  for (long long h = 0; h < n; h++) {
    cin >> s;
    v[s % m].push_back(s);
  }
  for (long long h = 0; h < n; h++) {
    if (v[h].size() >= k) {
      s = h;
      t = 1;
      break;
    }
  }
  if (t == 1) {
    cout << "Yes\n";
    for (long long h = 0; h < k; h++) {
      cout << v[s][h] << " ";
    }
  } else {
    cout << "No";
  }
  return 0;
}
