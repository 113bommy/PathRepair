#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int main(){
  int m,n;
  int b[1001];
  while(cin >> n >> m,m || n){
    int total=0;
    int k=n/m;
    for(int i=0;i<n;i++) cin >> b[i];
    sort(b,b+n);

    for(int i=1;i<=n;i++){
      if(i%m) total+=b[n-i];
    }
    cout << total << endl;
  }
}