N,X=list(map(int,input().split()))
L=list(map(int,input().split()))
cnt=1
d=0
for i in L:
    d+=i
    if d<=X:
        cnt+=1

print(cnt)
