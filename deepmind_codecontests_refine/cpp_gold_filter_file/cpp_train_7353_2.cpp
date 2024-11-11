#include <bits/stdc++.h>
using namespace std;
long long a[100007];
long long m[100007];
vector<long long> cnt;
int main() {
  long long n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    m[a[i]]++;
  }
  sort(a, a + n);
  bool oka = false;
  for (int i = 0; i <= a[n - 1]; i++) {
    if (m[i] % 2 == 1) {
      oka = true;
      break;
    }
  }
  if (oka)
    cout << "Conan" << endl;
  else
    cout << "Agasa" << endl;
}
