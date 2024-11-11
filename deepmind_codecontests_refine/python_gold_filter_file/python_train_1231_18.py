n,h=map(int,input().split())
a=[list(map(int,input().split()))for i in range(n)]
b=max(a,key=lambda x:x[0])[0]
c=sorted(t for(s,t)in a if t>b)
d=0
while h>0 and c:
    h-=c.pop()
    d+=1
print(d+max(h-1,-1)//b+1)