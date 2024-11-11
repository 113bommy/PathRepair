#include<iostream>
#include<cstdio>
#define N 1000000000
int tl[N];

using namespace std;

void sort(int,int);
int syori(int,int);

int main(){
  int n,m,i,ans;
  while(1){
    for(i=0;i<N;i++){
      tl[i]=0;
    }
    


  cin >> n; 
  cin >> m;

  if(m==0 && n==0) break;

  for(i=1;i<=n;i++){
    cin >> tl[i];
  }

  for(i=n+1;i<=(m+n);i++){
    cin >> tl[i];
  }

  sort(m,n);


  ans=syori(n,m);

  cout << ans << endl;

  }
return 0;
}


void sort(int m , int n){
  int i,j,max,hi;


  for(i=0;i<=(m+n);i++){
    max=i;
    for(j=i;j<=(m+n);j++){
      if(tl[j] < tl[max])max=j;
    }
    hi=tl[max];
    tl[max]=tl[i];
    tl[i]=hi;
  }


  //  for(i=0;i<=(m+n);i++){
  // cout << tl[i] << endl;;

  //}

}


int syori(int n, int m){
  int i,max=0;
  for(i=0;i<(m+n);i++){
    if(tl[i+1]-tl[i]>=max)max=tl[i+1]-tl[i];
  }

  return max;
}