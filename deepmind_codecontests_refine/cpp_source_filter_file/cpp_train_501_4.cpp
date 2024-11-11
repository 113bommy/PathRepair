#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,array[101];
  cin>>a;
  for(int i=0;i<a;i++){
    cin>>array[i];
  }
  sort(arrray,array+a);
  cout<<array[a-1]-array[0]<<endl;
}