#include <bits/stdc++.h>
using namespace std;
int n, m, k1, k2, ans = 0, a[1000000], b[1000000], x, y, z, MAX, MIN;
string str, str1, str2;
char C;
bool flag = false;
int cnn = 0;
long long int gemy[5000001] = {0};
int gemy2[5000001] = {0};
void sieve() {
  int temp;
  gemy2[1] = 0;
  for (int i = 2; i < 5000001; i++) {
    if (gemy2[i] == 0) {
      for (int j = i; j < 5000001; j += i) {
        temp = j;
        while (!(temp % i)) {
          temp /= i;
          gemy2[j]++;
        }
      }
    }
  }
}
int main() {
  long long int t, cnn2 = 0;
  sieve();
  for (long long int i = 2; i <= 5000000; i++) {
    gemy[i] = gemy2[i] + gemy[i - 1];
  }
  cin >> t;
  while (t--) {
    scanf("%d %d", &n, &m);
    printf("%d /n", gemy[n] - gemy[m]);
  }
}
