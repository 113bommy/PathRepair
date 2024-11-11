#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

map<string, int> dp;
int dx[4]={-1, 1, 4, -4};

void bfs(){
    string now="01234567";
    dp[now]=0;
    queue<string> q;
    q.push(now);
    while(q.size()){
        now=q.front(); q.pop();
        int z;
        for(int i=0; i<8; i++)
            if(now[i]=='0') z=i;
        for(int i=0; i<4; i++){
            int n=z+dx[i];
            if(n>=0&& n<8 &&(!(z==3&&i==1))&&(!(z==4&&i==0))){
                string next=now;
                swap(next[n], next[z]);
                if(dp.find(next)==dp.end()){
                    dp[next]=dp[now]+1;
                    q.push(next);
                }
            }
        }
    }
}
int main(){
    bfs();
    string line;
    while(getline(cin, line)){
        line.erase(remove(line.begin(), line.end(), " "), line.end());
        cout<<dp[line]<<endl;
    }
}
