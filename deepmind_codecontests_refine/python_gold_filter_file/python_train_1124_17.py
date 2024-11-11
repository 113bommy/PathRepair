I=input;n,q=map(int,I().split());s=' %s '%I();l,r=0,n+1
for t,_,d in eval('I(),'*q)[::-1]:L,R=d<'R',d>'L';l+=(t==s[l+1])*L-(t==s[l])*R;r+=(t==s[r])*L-(t==s[r-1])*R
print(max(0,r-l-1))