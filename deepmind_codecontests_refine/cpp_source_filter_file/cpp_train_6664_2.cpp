#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main(){
  string command;
  qriority_queue<int> q;
  while(cin >> command && command!="end"){
    if(command=="insert"){
      int n;
      cin >> n;
      q.push(n);
    }else{
      cout << q.top() << endl;
      q.pop();
    }
  }

  return 0;
}