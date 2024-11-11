#include <bits/stdc++.h>
using namespace std;
int main(){
  int h,n;	cin >> h >> n;
  int sum=0;
  for(int i=0;i<n;i++){
    int x;	cin >> x;
    sum+=x;
  }
  if(sum>=h)	cout<<"Yes";
  else cout<<"No";
}