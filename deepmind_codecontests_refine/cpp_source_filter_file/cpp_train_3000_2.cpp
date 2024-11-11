#include<bits/stdc++.h>

using namespace std;

void chmax( string &a, string b){
 if( a == "-"){ a = b;}// aが未更新だった場合
  //それ以外の場合はaとbの大小比較
  if( b.size() > a.size()){ a = b;}

  else{
    //aとbの桁数が一致した時、最高位から順に調べていく
   a = max( a, b); }
     }
}
 
 
  
int match[] = {0,2,5,5,4,5,6,3,7,6};


string dp[10100];
//dpは入力が整数で出力がstring

int main(){
int N,M; cin >> N >> M;
  vector<char> A(M);
  for(int i = 0; i < M; i++){ cin >> A[i];}
  for(int i = 0; i < 10100; i++){ dp[i] = "-";}
  //-は未記入 テーブルを記入していく
  dp[0] = ""; 
  for(int i = 0; i < 10010; i++){
    for(int j = 0; j < M; j++){
      //配るDP
   if( dp[i] != "-"){
   chmax( dp[i + match[A[j] - '0']], dp[i] + A[j]); }}}
  
  cout << dp[N] << endl; return 0;}
