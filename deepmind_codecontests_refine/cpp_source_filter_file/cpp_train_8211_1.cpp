#include <iostream>
#include <vector>
using namespace std;

int n, k;
string str;
int nxt[26];
vector<int> v[26];
int bit[200005];
inline void add(int i, int x){
  i++;
  while(i<200005){
    bit[i]+=x;
    i+=i&-i;
  }
}
inline int sum(int i){
  i++;
  int ret=0;
  while(i){
    ret+=bit[i];
    i-=i&-i;
  }
  return ret;
}

void gonext(int i){
  
}
int main(){
  cin >> str >> k;
  n=str.length();
  fill(bit, bit+200005, 0);
  fill(nxt, nxt+26, 0);
  for(int i=0; i<n; i++){
    add(i, 1);
    v[str[i]-'a'].push_back(i);
  }
  for(int i=0; i<n; i++){
    for(int j=0; j<26; j++){
      if(nxt[j]==v[j].size()) continue;
      int cnt=sum(v[j][nxt[j]]-1);
      if(cnt<=k){
        k-=cnt;
        add(v[nxt[j]], -1);
        cout << (char)('a'+j);
        if(nxt[j]<v[j].size()) nxt[j]++;
        break;
      }
    }
  }
  cout << endl;
}