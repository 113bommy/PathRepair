#include<bits/stdc++.h>
using namespace std;
long long n, i, j, a[1<<18], b, c, d;


int main(){
  cin >> n;
  for(i=1;i<=n;++i){
    cin >> a[i];
    b += a[i];
  }
  c = b;
  for(i=1; i<=n;++i){
    d += a[i];
    c = min(c, abs(d-(b-d)));
  }
  cout <<c;
}
