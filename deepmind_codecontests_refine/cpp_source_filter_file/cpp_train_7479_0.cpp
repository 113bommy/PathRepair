#define ASIZE 200005
#include <bits/stdc++.h>
using namespace std;
long long ft[ASIZE],n=ASIZE+1;
typedef pair<long long,long long> pii;

void increment(long long p){
  for(;p<=n;p+=(p & -p))ft[p]++;
}

long long query(long long p){
  long long sum=0;
  for(;p>0;p-=(p & -p))sum+=ft[p];
  return sum;
}

long long main() {
  long long n,k,a[ASIZE]={0},ps[ASIZE],x,sum=0;
  priority_queue<pii,vector<pii>,greater<pii> >pq;
  cin>>n>>k;
  for(long long i=1;i<=n;i++){
    cin>>a[i];
    a[i]-=k;
    ps[i]=ps[i-1]+a[i];
    pq.emplace(ps[i],i);
  }
  while(!pq.empty()){
    x=pq.top().second;
 //   cout<<"x= "<<x<<"\n";
    sum+=query(x);
    increment(x);
    if(pq.top().first>=0)sum++;
    pq.pop();
  }
  cout<<sum;
  return 0;
}