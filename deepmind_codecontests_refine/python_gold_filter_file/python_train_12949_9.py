n=int(input())
l=list(map(int,input().split()))
m=min(l)
f=0
for i in l:
    if i%m!=0:
        f=1
        break
if f:
    print(-1)
else:
    print(m)