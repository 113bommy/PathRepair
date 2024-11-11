#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,k;
  cin >> n;
  k=30;
  
  for(int i=0;i<n;i++){
    int a[i];
    cin >> a[i];
    int D=0;
    
    while(a[i]%2==0){
      D++;
      a[i]/=2;
    }
    k=min(D,k);
  }
	cout << k <<endl;
}
