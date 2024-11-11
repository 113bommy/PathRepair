#include<iostream>
using namespace std;

int main(){
int n,m,a,b;
int sum[100];
int big[100];
while(cin>>n>>m){
for(int i=0;i<100;i++){
sum[i]=0;}
b=0;
for(int i=0;i<n;i++){
for(int j=0;j<m;j++){
cin>>a;
sum[j]+=a;}}
for(int i=1000;i>-1;i--){
for(int j=0;j<m;j++){
if(i==sum[j]){
if(b!=m-1){
cout<<j+1<<" ";}
if(b==m-1){
cout<<j+1<<endl;}
b++;}}
}}