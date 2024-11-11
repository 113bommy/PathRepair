#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k;
  scanf("%lld %lld", &n, &k);
  vector<long long> v;
  long long temp = 0;
  long long input;
  for (int i = 0; i < n; i++) {
    scanf("%lld", &input);
    v.push_back(input);
    temp += input;
  }
  long long cnt = 0;
  long long jml = 0;
  long long ini = 0;
  vector<long long> ans;
  if (temp % n == 0) {
    temp = temp / k;
    for (int i = 0; i < v.size(); i++) {
      cnt += v[i];
      ini++;
      if (cnt == temp) {
        ans.push_back(ini);
        cnt = 0;
        ini = 0;
      }
      if (cnt > temp) {
        jml = -1;
        break;
      }
    }
    if (jml == -1)
      puts("No");
    else {
      puts("Yes");
      for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
      }
    }
  } else
    puts("No");
}
