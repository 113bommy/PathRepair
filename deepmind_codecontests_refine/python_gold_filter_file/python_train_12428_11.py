n=int(input())
a=list(map(int,input().split()))
a.sort()
cnt=0
for i in range(n):
    cnt+=(abs(a[i]-(i+1)))
print(cnt)