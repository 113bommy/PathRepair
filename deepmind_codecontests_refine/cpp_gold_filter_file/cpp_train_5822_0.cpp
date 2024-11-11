#include<iostream>
using namespace std;

int main(){
 while(true){
  int M, T, P, R;
  cin >> M >> T >> P >> R;

  if(M==0 && T==0 && P==0 && R==0) break;

  int CP[T],  TT[T],  PT[T][P]; //正解数、時間計、ペナルティ
  for(int i=0; i<T; i++){
   CP[i] = TT[i] = 0;
   for(int j=0; j<P; j++){
    PT[i][j] = 0;
   }
  }

  for(int i=0; i<R; i++){ //各チームの正解数、時間計を求める
   int m, t, p, j;
   cin >> m >> t >> p >> j;
   
   if(j==0){ //正解
    CP[t-1]++;
    TT[t-1] += (m+PT[t-1][p-1]);
   }else{ //不正解
    PT[t-1][p-1] += 20;
   }
  }

   int t_now, t_pre = -1; //今のチーム、1つ前のチーム
   bool flag[50]; //処理済みフラグ
   for(int i=0; i<T; i++){
    flag[i] = false;
   }
   
   for(int i=0; i<T; i++){
    t_now = -1;
    for(int j=0; j<T; j++){ //今のチームを求める
     if(flag[j]) continue;
     if(t_now==-1){
      t_now = j;
     }else{
      if(CP[j]>CP[t_now] || (CP[j]==CP[t_now] && TT[j]<=TT[t_now])){
       t_now = j;
      }
     }
    }

    if(t_pre!=-1){
     if(CP[t_now]==CP[t_pre] && TT[t_now]==TT[t_pre]){
      cout << '=';
     }else{
      cout << ',';
     }
    }
    cout<<t_now+1;

    flag[t_now] = true;
    t_pre = t_now;
   }
   cout << endl;
  }
  return 0;
}
