from sys import stdin
n,m=map(int,stdin.readline().strip().split())
s=list(map(int,stdin.readline().strip().split()))
sm=sum(s)
if sm<m:
    print(-1)
    exit(0)
s.sort(reverse=True)
low=0
high=n
while high-low>1:
    mid=(high+low)//2
    x=0
    t=0
    y=round(n/mid)
    s1=[y]*mid
    q=n-y*mid
    while q<0:
        s1[q]=s1[q]-1
        q+=1
    while q>0:
        s1[q-1]=s1[q-1]+1
        q-=1
    w=1
    o=1
    for j in range(n):
        t+=max(s[j]-x,0)

   
        if (j+1)%mid==0 :
            x+=1

    if t>=m:
        high=mid
    else:
        low=mid
print(high)
            
    
            
            
    
    
    
