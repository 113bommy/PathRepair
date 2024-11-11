#include <bits/stdc++.h>
using namespace std;
 
int main() {
int N,a[100],res=0;
  cin >> N;
  for(int i=0;i<N;i++){
   cin >> a[i];
    if(i%2==0 && a[i]%2==1){
res++;    
    }
  }
  cout << res;
}