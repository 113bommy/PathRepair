#include<bits/stdc++.h>
using namespace std;

int main(){
  int a,b,n;
  while(cin >> a >> b >> n){
    int k = a % b * 10;
    s = 0;
    for(int i=0;i<n;i++){
      s += k / b;
      k = k % b * 10;
    }
    cout << s << endl;
  }
}