#include<bits/stdc++.h>
using namespace std;
int main(){
 int n,count=0;
 cin >> n;
 int a[n];
 for(int i=0;i<n;i++){
  cin >> n[i];
  if(i!=0 && n[i-1]==n[i]){
   n[i]=0;
   count++;
  }
 }
 cout << count << endl;
}