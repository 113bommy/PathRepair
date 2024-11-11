#include<bits/stdc++.h>
using namespace std;
short cnt[4100][4100];
int main(){
  string str1,str2;
  while(cin >> str1){
    cin >> str2;
    int len1 = str1.size();
    int len2 = str2.size();
    str1 = ' ' + str1;
    str2 = ' ' + str2;
    for(int i=1;i<=len1;i++){
      cnt[i][0] = 0;
    } 
    for(int i=1;i<=len2;i++){
      cnt[0][i] = 0;
    }
    short ret = 0;
    for(int i=1;i<=len1;i++){
      for(int j=1;j<=len2;j++){
	if(str1[i] == str2[j]){
	  cnt[i][j] = cnt[i-1][j-1] + 1;
	}
	else {
	  cnt[i][j] = 0;
	}
	ret = max(ret,cnt[i][j]);
      }
    }
    cout << ret << endl;
  }	
}