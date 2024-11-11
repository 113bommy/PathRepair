n=int(input())
a=list(map(int,input().split()))
i=1
cnt=0
for x in a:
    if x==i:i+=1
    else:cnt+=1
if cnt==n:print(-1)
else:print(cnt)