from collections import defaultdict
import sys
input=sys.stdin.readline
n,h,m,k=map(int,input().split())
l=[]
a=[]
start=0
for i in range(n):
    H,M=map(int,input().split())
    M=M%(m//2)
    a.append(M)
    l.append((M+1,1,i))
    l.append(((M+k)%(m//2),-1,i))
    if (M+1)>(M+k)%(m//2):
        start+=1
l.append((0,0,0))
l.append((m//2-1,0,0))
l.sort()
#print(l)
p=-1
ans=(10000000000,0)
for t,dire,ind in l:
    #print(start,t)
    if p!=-1 and p!=t:
        ans=min(ans,(start,p))
    start+=dire
    p=t
print(*ans)
time=ans[1]
if ans[0]>0:
    for i in range(n):
        #print(a[i]+1,(a[i]+k)%(m//2),time)
        if (a[i]+1)>(a[i]+k-1)%(m//2):
            if time>=a[i]+1 or time<=((a[i]+k-1)%(m//2)):
                print(i+1)
        else:
            if time>=a[i]+1 and time<=((a[i]+k-1)%(m//2)):
                print(i+1)