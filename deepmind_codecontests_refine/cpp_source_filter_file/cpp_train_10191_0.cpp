#include<bits/stdc++.h>
using namespace std;
#define MAX_N 100001
int n;
double X[MAX_N],R[MAX_N];
 
bool check(double y){
  double l=-1e9;
  double r=1e9;
  for(int i=0;i<n;i++){
    double a=X[i]- sqrt(R[i]*R[i]-y*y);
    l=max(l,a);
    double b=X[i]+ sqrt(R[i]*R[i]-y*y);
    r=min(r,b);
  }
  return (l<r);
}
 
int main(){
  double left=0,right=1e9,mid;
   
  cin>>n;
  for(int i=0;i<n;i++){
    int x,r;
    cin>>x>>r;
    X[i]=x;
    R[i]=r;
 
    right=min(right,R[i]);
  }
 
  for(int i=0;i<100;i++){
    mid=(left+right)*0.5;
    if(check(mid))left=mid;
    else right=mid;
  }
 
  printf("%.10f\n",left);
   