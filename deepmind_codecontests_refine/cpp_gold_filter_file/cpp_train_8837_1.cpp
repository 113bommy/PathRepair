#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

struct T{
  int v,r;
};

struct S{
  int v,c,r;
  bool operator<(S s)const{
    return c>s.c;
  }
};

int N,K;
int C[5001],R[5001];
vector<int> G[5001];

int main(){
  cin>>N>>K;
  for(int i=1;i<=N;i++){
    cin>>C[i]>>R[i];
  }
  while(K--){
    int A,B;
    cin>>A>>B;
    G[A].push_back(B);
    G[B].push_back(A);
  }
  priority_queue<S> que;
  que.push({1,0,0});
  static bool mem[5001][5001];
  for(;;){
    S cs=que.top();
    if(cs.v==N)break;
    que.pop();
    if(mem[cs.v][cs.r]++)continue;
    que.push({cs.v,cs.c+C[cs.v],R[cs.v]});
    if(cs.r){
      for(auto e:G[cs.v]){
	que.push({e,cs.c,cs.r-1});
      }
    }
  }
  cout<<que.top().c<<endl;
}