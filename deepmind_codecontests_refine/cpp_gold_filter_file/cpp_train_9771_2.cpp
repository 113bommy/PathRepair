#include <bits/stdc++.h>
using namespace std;

int main(){
  string c;
  cin>>c;
  regex re("[aouie]");
  cout<<(regex_match(c,re)?"vowel":"consonant")<<endl;
    return 0;
}