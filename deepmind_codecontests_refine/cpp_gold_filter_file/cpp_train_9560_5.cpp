#include <bits/stdc++.h>
using namespace std;
int main() {
  int A,B,ans=0;
  cin >> A >> B;
  for(int i=A;i<=B;i++){
    if(i/10000==i%10 && i/1000%10==i%100/10) ans++;
  }
  cout << ans << endl;
}