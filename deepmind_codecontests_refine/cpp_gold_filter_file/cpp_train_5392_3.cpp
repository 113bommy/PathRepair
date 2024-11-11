#include <iostream>
using namespace std;

int n;
char arr[101];

int main(void){
  cin>>n;
  if(n%2==1){cout<<"No";return 0;}
  cin>>arr;
  for(int i=0;i<n/2;i++)if(arr[i]!=arr[i+n/2]){cout<<"No";return 0;}
  cout<<"Yes";
 return 0; 
}