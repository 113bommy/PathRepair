#include <iostream>
using namespace std;

#define check cnt=0;for(j=0;j<6;j++)if(d1[j]==d2[j])cnt++;
#define r tmp=d2[1];d2[1]=d2[3];d2[3]=d2[4];d2[4]=d2[2];d2[2]=tmp;
#define y tmp=d2[0];d2[0]=d2[3];d2[3]=d2[5];d2[5]=d2[2];d2[2]=tmp;

bool same(){int d1[],int d2[]);
 int tmp,cnt,j,a=1,i,k;
 check
   if(cnt==6)a=0;

 while(a){
  for(i=0;i<5;i++){
   for(k=0;k<4;k++){
    check
    if(cnt==6)break;
    r
   }
   check
   if(cnt==6)break;
   tmp=d2[0];
   d2[0]=d2[1];
   d2[1]=d2[5];
   d2[5]=d2[4];
   d2[4]=tmp;
  }
  if(cnt==6)break;
  y
  for(k=0;k<4;k++){
   check
   if(cnt==6)break;
   r
  }
  if(cnt==6)break;
  y
  y
  for(k=0;k<4;k++){
   check
   if(cnt==6)break;
   r
  }
  a=0;
 }

 if(cnt==6)return true;
 return false;

}


int main(){
 int d1[6],d2[6],tmp,cnt,j,a=1,i,k,judge;

 for(int i=0;i<6;i++){
  cin >> d1[i] ;
 }
 for(int i=0;i<6;i++){
  cin >> d2[i] ;
 }

 if(same(d1,d2))judge=1;
 else judge=0;

 if(judge==1)cout << "Yes" << endl ;
 else cout << "No" << endl ;

 return 0;
}