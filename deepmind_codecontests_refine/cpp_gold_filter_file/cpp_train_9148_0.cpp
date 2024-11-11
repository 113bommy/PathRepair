#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

int64 memo[1111][1111];

 

int64 dfs(int i,int cnt);

string t,b;

 

int main(){

  for(int i = 0;i < 1111;i++){

    for(int j = 0;j < 1111;j++){

      memo[i][j] = -1;

    }

  }

  t += '0';

  string a;

  cin >> a >> b;

  t += a;

  cout << dfs(0,0) << endl;

  return 0;

}

 

int64 dfs(int i,int cnt){

  int rec = 0;

  if(cnt == b.size())return 1;

  if(memo[i][cnt] != -1)return memo[i][cnt];

  for(int j = i + 1;j < t.size();j++){

    if(t[j] == b[cnt])rec = (rec + dfs(j,cnt + 1)) % 1000000007;

  }

  return memo[i][cnt] = rec % 1000000007;

}