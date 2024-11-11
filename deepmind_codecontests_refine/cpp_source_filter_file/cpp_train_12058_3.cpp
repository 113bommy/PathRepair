#include <iostream>
using namespace std;
string S[1000];
int N;
int main(){
  cin >> N;
  bool judge = true;
  for(int i=0;i<N;i++){
	cin >> S[i];
    if(i>=1){
		if(S[i][0]!=S[i-1][S[i-1].size()-1]) judge = false;
    }
  }
  for(int i=0;i<N-1;i++){
	for(int j=i+1;j<N;j++){
      if(S[i]==S[j]) judge = false;
  }
  cout << (judge? "Yes":"No") << endl;
}
  
