#include<iostream>
using namespace std;
int c[200001];
int main(){
 
  int n,a,i;
  cin >> n;
  for(i=1;i<n;i++){
    cin >> a;
    c[a]++;
  }
  for(i=1;i<=n;i++){
    cout << c[i] << endl;
  }  
  return 0;

  
}