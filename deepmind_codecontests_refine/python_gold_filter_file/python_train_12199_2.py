import sys
import math
input=sys.stdin.readline

s1=input()
t1=input()
s=s1.rstrip()
t=t1.rstrip()

mini=list()
maxi=list()
st=0

for i in range(len(s)):
    if(s[i]==t[st]):
        mini.append(i)
        st+=1
    if(st==len(t)):
        break
st=len(t)-1
for i in range(len(s)-1,-1,-1):
    if(s[i]==t[st]):
        maxi.append(i)
        st-=1
    if(st==-1):
        break
maxi.reverse()
ans=maxi[0]

ans=max(len(s)-1-mini[len(t)-1],ans)

for i in range(1,len(t)):
    ans=max(maxi[i]-mini[i-1]-1,ans)
if(len(s)==len(t)):
    print(0)
else:    
    print(ans)
    
        
    
    
