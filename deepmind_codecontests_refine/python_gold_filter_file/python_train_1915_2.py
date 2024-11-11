n,x=map(int,input().split())
a=list(map(int,input().split()))
d={1:0}
for i in a:
     if i==1:
          d[i]+=1
o=min(d[1],n-d[1])
k=[]
for i in range(x):
     l,r=map(int,input().split())
     k.append(int((l+r+1)&1==0 and o>=(r-l+1)//2))
print(*k)
          
