#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
  int N,C,K;
  cin >> N >> C >> K;
  vector<int> T[N];
  for(int i=0; i<N;++i)cin >> T[i];
  sort(T.begin(),T.end());
  int res=0,j;
  for(int i=0;i<N;){
    res++;
    j=i;
    while(i<N && T[i]-T[j] && i-j<C)i++;
  }
  cout << res << endl;
}
