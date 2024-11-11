n,k=map(int,input().split())
holidays=[int(i) for i in input().split()]
holidays.pop(0)
if k==1:
    print(n)
    exit()
from math import ceil 
cnt=0
prev=0
for i in range(1,n+1):
    if i in holidays:
        cnt+=1 
        #print(i)
        prev=i 
    elif i-prev>=k:
        cnt+=1 
        prev=i 
        #print(i,'k')
print(cnt)