#include <bits/stdc++.h>

struct Point{
  int x;
  int y;
};

bool operator<(Point a, Point b){
  return a.x+a.y<b.x+b.y;
}

long long mo=(long long)1e9+7;
long long fac[200000];
long long ifac[200000];

Point point[30001];
int H,W,N;

long long pow(long long a,long long n){
  long long ret=1;
  for(;n>0;n>>=1,a=a*a%mo){
    if(n%2==1){
      ret=ret*a%mo;

    }
  }
  return ret;
}

long long inv(long long a){
  return pow(a,mo-2);
}


void build(){
  fac[0]=1;
  ifac[0]=1;
  for(int i=1;i<200000;++i){
    fac[i]=fac[i-1]*i%mo;
    ifac[i]=inv(fac[i]);
  }
}

long long comb(int n,int k){
  return fac[n]*ifac[k]%mo*ifac[n-k]%mo;
}

long long dp[3001];

int main(){
  build();
  std::cin>>H>>W>>N;
  for(int i=0;i<N;++i){
    std::cin>>point[i].y>>point[i].x;
    --point[i].x;
    --point[i].y;
  }
  point[N].y=H-1;
  point[N].x=W-1;
  std::sort(point, point+N);
  for(int i=0;i<=N;++i){
    dp[i]=comb(point[i].y+point[i].x,point[i].x);
    for(int j=0;j<i;++j){
      int dx=point[i].x-point[j].x;
      int dy=point[i].y-point[j].y;
      if(dx<0||dy<0)continue;
      dp[i]=(dp[i]-dp[j]*comb(dx+dy,dx)%mo+mo)%mo;
    }
  }
  std::cout<<dp[N]<<std::endl;
  return 0;
}
