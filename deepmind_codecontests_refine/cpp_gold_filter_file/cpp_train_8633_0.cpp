#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define rep1(i,n) for(int i=1;i<=int(n);++i)
#define all(a) a.begin(),a.end()

bool eval(vector<int> &table,string &s,int &i){
    if(isdigit(s[i])) return s[i++] == '1';
    if(s[i] == '-') return !eval(table,s,++i);
    if(isalpha(s[i])) return table[s[i++]-'a'];
    i++; // (
    bool e1 = eval(table,s,i);
    char op = s[i++];
    bool e2 = eval(table,s,i);
    i++; // )
    if(op == '^') return e1^e2;
    if(op == '*') return e1*e2;
    assert(false);
}

int feature(string &E){
    int k = 0;
    int f = 0;
    rep(a,2)rep(b,2)rep(c,2)rep(d,2){
        vector<int> table = {a,b,c,d};
        int i = 0;
        if(eval(table,E,i)){
            f |= 1<<k;
        }
        k++;
    }
    return f;
}

int main(void){
    vector<string> exps[17];
    exps[1] = {"a","b","c","d"};
    for(int m = 2; m <= 16; m++){
        for(string E : exps[m-1]){
            if(E[0] == '-') continue;
            exps[m].push_back("-"+E);
        }
        rep1(x,m-2){
            int y = m-3-x;
            if(x>y) continue;
            for(string E1 : exps[x]){
                for(string E2 : exps[y]){
                    bool ng = false;
                    for(char ch : {'a','b','c','d'}){
                        if(count(all(E1),ch)+count(all(E2),ch)>1){
                            ng = false;
                        }
                    }
                    if(ng) continue;
                    exps[m].push_back("("+E1+"^"+E2+")");
                    exps[m].push_back("("+E1+"*"+E2+")");
                }
            }
        }
    }
    exps[1].push_back("0");
    exps[1].push_back("1");


    vector<int> min_len(1<<16, 20);
    rep1(m,16){
        for(string E : exps[m]){
            int f = feature(E);
            min_len[f] = min(min_len[f], m);
        }
    }

    string E;
    while(cin>>E, E != "."){
        cout<<min_len[feature(E)]<<endl;
    }
    return 0;
}

