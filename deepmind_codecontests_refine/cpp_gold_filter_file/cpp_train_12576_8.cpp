#include<bits/stdc++.h>
using namespace std;

int main(void){
  int N;
  int A = 0; // xxxxxA
  int B = 0; // Bxxxxxx
  int AB = 0; // BxxxxxxA
  int out = 0;

  cin >> N ;
  for(int i = 0; i < N;i++){
    string s;
    cin >> s ;
    if (s[0] == 'B'){
      if(s[s.size() - 1] == 'A')AB++;
      else B++;
    }
    else{
      if(s[s.size() - 1] == 'A')A++;
    }
    for( int j = 0; j < s.size()-1;j++)
      if(s[j] == 'A' && s[j+1] == 'B')out++;
  }
  int k = min(A,B) + AB;
  if(A+B == 0 && AB != 0)k--;
  out += k;
  cout << out << endl;
}
