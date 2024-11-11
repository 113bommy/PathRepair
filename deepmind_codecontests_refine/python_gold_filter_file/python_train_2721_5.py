n=int(input())
l=list(map(int,input().split()))
c=0
d=0
for i in l:
    if i/1>0:
        c+=1
for i in l:
    if i/(-1)>0:
        d+=1
if c>=n/2:
    print(1)
elif d>=n/2:
    print(-1)
else:
    print(0)