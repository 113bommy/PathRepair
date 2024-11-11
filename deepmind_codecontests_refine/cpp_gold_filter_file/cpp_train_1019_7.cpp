#include <iostream>
using namespace std;
//dp[i]:1~iまでの黒の石の数
int B[200001]={0};

int main(){
  int N;
  string str;
  cin >> N >> str;
  for(int i=0;i<N;i++){
    B[i+1]=B[i];
    if(str[i]=='#')B[i+1]++;
  }
  int ans=N+1;
  for(int i=0;i<=N;i++)ans=min(B[i]+(N-i)-(B[N]-B[i]),ans);
  cout << ans << endl;
  return 0;
}
