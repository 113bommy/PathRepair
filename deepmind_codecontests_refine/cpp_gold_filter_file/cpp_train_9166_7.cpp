#include<iostream>
using namespace std;

int main(){
  int n, taro=0, hanako=0;
  string t, h;

  cin>>n;
  for(int i=0;i<n;i++){
    cin>>t>>h;
    if(t>h) taro+=3;
    else if(t<h) hanako+=3;
    else{
      taro++;
      hanako++;
    }
  }

  cout<<taro<<" "<<hanako<<endl;

  return 0;
}