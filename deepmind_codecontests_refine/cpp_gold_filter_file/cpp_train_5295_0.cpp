#include<bits/stdc++.h>
std::string s;
int main(){
    std::cin>>s;
    puts(((s[0]==s[s.length()-1])^(s.length()%2))?"First":"Second");
}