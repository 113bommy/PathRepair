#include<bits/stdc++.h>
using namespace std;
const double pi=acos(-1.0);
int main(){
   double a,b,h,m;
   cin>>a>>b>>h>>m;
   double ans=a*a+b*b-2*a*b*cos(2*M_PI*((h+m/60)/12-m/60));
   printf("%.12lf\n",sqrt(ans));
   return 0;