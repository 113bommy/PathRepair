#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
#define INF 10000000
using namespace std;
typedef pair<int,int> P;


void swap(char *a,char *b){
  char temp = *a;
  *a = *b;
  *b = temp;
}

int main(){
  int dx[] = {+1,-1,+4,-4};

  string start = "01234567";

  queue<string> que;
  map<string,int> d;
  que.push(start);
  d[start] = 0;

  while(que.size()){
    string q = que.front(); que.pop();
    int x = q.find("0");
    for(int i=0;i<4;i++){
      int next = x + dx[i];
      if( next>=0 && next<=7 && !(x==3&&next==4) && !(x==4&&next==3) ){
        string nextq = q;
        swap(&nextq[x],&nextq[next]);
        if(d.find(nextq)==d.end()){
          que.push(nextq);
          d[nextq] = d[q] + 1;
        }
      }
    }
  }

  while(1){
    string input = "";
    char temp;
    for(int i=0;i<8;i++){
      if(cin >> temp){
        input.push_back(temp);
      }else{
        return 0;
      }
    }
    cout << d[input] << endl;
  }

}