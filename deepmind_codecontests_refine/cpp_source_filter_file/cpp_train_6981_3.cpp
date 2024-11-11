#include<iostream>
using namespace std;

int main(){

int a[5][4][11],n;
for (int i=0;i<5;i++)
for (int j=0;j<4;j++)
for (int k=0;k<11;k++) a[i][j][k]=0;

cin >>n;
for(int i=0;i<n;i++){
int b,f,r,v;
cin >>b >>f >>r >>v;
a[b][f][r]+=v;
}

for (int f=1;f<=4;f++){
if(f>1)cout "####################\n";
for(int b=1;b<=3;b++){
for(int r=1;r<=10;r++){
cout <<" "<<a[f][b][r];
}
cout <<endl;
}
}
return 0;
}