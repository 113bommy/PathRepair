#include<iostream>
using namespace std;

int main(){
  int n,m,k,ans;
  cin >> n >> m >>k;
  for(int i=0;i<=m;i++){
    for(int j=0;j<=n;j++){
      if( (n*i+(m-a)*j) ==k ){
        cout << "Yes" <<endl;
        return 0;
      }
    }
  }
  cout << "No" <<endl;
  return 0;
}
