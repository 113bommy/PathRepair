#include<bits/stdc++.h>
using namespace std;
int main(){
 int n,count=0;
 cin >> n;
 int a[n];
 for(int i=0;i<n;i++){
  cin >> a[i];
  if(i!=0 && a[i-1]==a[i]){
   a[i]=0;
   count++;
  }
 }
 cout << count << endl;
}