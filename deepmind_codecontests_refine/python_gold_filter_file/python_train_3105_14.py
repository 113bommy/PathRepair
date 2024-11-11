# 2019/09/03

n=int(input())
a=list(map(int,input().split()))

cnt=0
for i in range(1,n):
    if a[i-1]==a[i]:
        a[i]=-1
        cnt+=1
print(cnt)