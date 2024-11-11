#include <bits/stdc++.h>
using namespace std;


int main(){
  int N;
  cin>>N;
  int p=-1;
  int a[N];
  int ans = 0;
  for(int i=0;i<N;i++){
    cin>>a[i];
    if(a[i] == p){
      ans++;
      p=-1;
    }
    else p=a[i];
  }
  cout << ans << endl;
}

