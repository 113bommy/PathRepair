#include<iostream>
using namespace std;
int c[200001];
int main(){
 
  int n,a;
  cin >> n;
  for(i=0;i<n;i++){
    cin >> a;
    c[a]++;
  }
  for(i=1;i<=n;i++){
    cout << c[a] << endl;
  }  
  return 0;

  
}