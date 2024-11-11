#include <iostream>
using namespace std;
int main(){
  int n;cin>>n;
  int a[n];
  for(int i = 0; n > i; i++)cin>>a[i];
  int mx = 0;
  for(int i = 0; n > i; i++){
    if(mx > a[i]){
      cout << "No" << endl;
      return 0;
    }
    mx = max(mx,a[i]-1);
  }
  cout << "Yes" << endl;
    