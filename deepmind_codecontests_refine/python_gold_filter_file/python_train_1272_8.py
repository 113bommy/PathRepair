n = int(input())
l = list(map(int,input().split()))
idx = 0
for i in range(30,-1,-1):
    cnt = 0
    for j in range(n):
        if l[j]&(1<<i):
            cnt+=1
            idx = j
    if cnt==1:
        break
print(l[idx],*l[idx+1:],*l[:idx])