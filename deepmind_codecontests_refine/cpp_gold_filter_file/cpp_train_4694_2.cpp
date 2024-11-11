#include<bits/stdc++.h>
using namespace std;

int n;
double x[100],y[100];

double distance(double p){
double sum=0;
for(int i=0;i<n;i++){
double w=abs(x[i]-y[i]);
sum+=pow(w,p);
}
return pow(sum,1/p);
}

int main(){
cout<<fixed<<setprecision(12);
cin>>n;
for(int i=0;i<n;i++){
cin>>x[i];
}
for(int i=0;i<n;i++){
cin>>y[i];
}
cout<<distance(1)<<endl;
cout<<distance(2)<<endl;
cout<<distance(3)<<endl;

double mx=0;
for(int i=0;i<n;i++){
mx=max(mx,abs(x[i]-y[i]));
}
cout<<mx;
return 0;
}
