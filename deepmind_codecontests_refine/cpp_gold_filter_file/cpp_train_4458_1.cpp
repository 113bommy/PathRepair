#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  double ans;
  double x;
  string u;
  for (int i;i<N;i++){
    cin >>x>>u;
    ans=u=="JPY"?ans+x:ans+x*380000.0;
  }
  cout << ans << endl;
}
