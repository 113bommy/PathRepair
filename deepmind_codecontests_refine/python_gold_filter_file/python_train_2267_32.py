x,n=map(int,input().split())
p=list(map(int,input().split()))
p.sort()
ans=300
for i in range(-100,200):
    if p.count(i)==0:
        if abs(ans-x)>abs(i-x):
            ans=i
print(ans) 