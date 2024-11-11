#inclde<iostream>
int m=1e9+7;
int main(){int N,M;std::cin>>N>>M;long d[N+1],a=M-N+1;d[0]=1,d[1]=M-N;for(int i=2;i<=N;i++){d[i]=((M-N+i-1)*d[i-1]+(i-1)*d[i-2])%m;a=a*(M-i+2)%m;}std::cout<<a*d[N]%m;}
