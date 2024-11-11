#include<bits/stdc++.h>
#define MAX 100005
using namespace std;

int n;
long long ans, ans2, ans3, a[200002], c, d;

int main(){
  cin >> n >> c >> d;
  ans2 = c;
  ans3 = d;
  for(int i = 0; i < n - 1; i++){
    cin >> a[i * 2] >> a[i * 2 + 1];
    ans2 += a[i * 2];
    ans3 += a[i * 2 + 1];
    if(max(a[i * 2], a[i * 2 + 1]) < max(c, d)){
      swap(a[i * 2], c);
      swap(a[i * 2 + 1], d);
    }
  }
  sort(a, a + 2 * n - 2);
  for(int i = 0; i < n - 2; i++)
    ans += a[i];
  ans += min(c + d, a[n - 2] + a[n - 1]);
  cout << min(ans, min(ans2, ans3));
  return 0;
}
