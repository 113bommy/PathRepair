n=int(input())
cnt=0
for i in range(n):
    a,b=map(int,input().split())
    if abs(a-b)>=2:
        cnt+=1
print(cnt)
