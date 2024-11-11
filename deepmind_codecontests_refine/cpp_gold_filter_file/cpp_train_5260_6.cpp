#include <bits/stdc++.h>
using namespace std;
int BinarySearch(vector<int> &A, int x) {
  int l = 0;
  int r = A.size() - 1;
  if (l > r) {
    return -1;
  }
  while (l <= r) {
    int mid = (l + r) / 2;
    if (A[mid] == x) {
      return mid;
    }
    if (A[mid] > x) {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  return -1;
}
unsigned long long gcd(unsigned long long a, unsigned long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
unsigned long long lcm(unsigned long long mgcd, unsigned long long a,
                       unsigned long long b) {
  return a * b / mgcd;
}
int solution(vector<int> &A, vector<int> &B) {
  int asize = (int)A.size();
  int bsize = (int)B.size();
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  int i = 0, j = 0;
  while (i < asize && j < bsize) {
    if (A[i] == B[j]) {
      return A[i];
    }
    if (A[i] < B[j]) {
      i++;
    } else {
      j++;
    }
  }
  return -1;
}
int main() {
  int n, k;
  string str;
  scanf("%d %d\n", &n, &k);
  getline(cin, str);
  long long sum = 0;
  for (int i = 0; i < str.length(); i++) {
    sum += max(abs('z' - str[i]), abs(str[i] - 'a'));
  }
  if (sum < k) {
    printf("%d", -1);
    return 0;
  }
  for (int i = 0; i < str.length(); i++) {
    int l = abs('a' - str[i]);
    int r = abs('z' - str[i]);
    if (k <= 0) {
      printf("%c", str[i]);
    } else if (r - k >= 0) {
      printf("%c", (char)(str[i] + k));
      k = 0;
    } else if (l - k >= 0) {
      printf("%c", (char)(str[i] - k));
      k = 0;
    } else {
      if (r > l) {
        k -= r;
        printf("%c", 'z');
      } else {
        k -= l;
        printf("%c", 'a');
      }
    }
  }
  printf("\n");
  return 0;
}
