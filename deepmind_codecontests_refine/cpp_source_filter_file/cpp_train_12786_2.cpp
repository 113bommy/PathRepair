#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin>>N;
  string ans="No";
  for(int i=0;i<N/4;i++){
    if((N-4*i)%7==0){
      ans="Yes";
      break;
    }
  cout << ans << endl;
}
