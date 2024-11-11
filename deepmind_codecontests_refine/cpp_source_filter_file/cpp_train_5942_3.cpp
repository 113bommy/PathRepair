#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
int main(){

int i,n;
double score[1000],ave=0,sigma;

while(1){

ave=sigma=0;
cin>>n;
if(n==0)return 0;

for(i=0; i<n; i++){
cin>>score[i];
ave+=score[i];
}

ave/=(double)n;

for(i=0; i<n; i++)sigrma+=(double)(score[i]-ave)*(score[i]-ave);

printf("%.8f\n",sqrt(sigma/(double)n));

}

}