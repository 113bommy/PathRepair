from sys import stdin,stdout
from bisect import bisect,bisect_left
k=int(input())
s=stdin.readline().rstrip('\n')
if k==0:
    l1=s.split('1')
    ans=0
    for i in l1:
        ln=len(i)
        ans+=(ln*(ln+1))//2
else:
    l=[0]
    c=0
    for i in s:
        if i=='1':
            c+=1
        l.append(c)
    n=len(s)
    ans=0
    for i in range(1,n+1):
        a=bisect(l,l[i-1]+k)
        b=bisect_left(l,l[i-1]+k)
        ans+=a-b
print(ans)
    
    
