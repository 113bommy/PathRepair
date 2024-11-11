n=int(input())
count=0
for _ in range(n):
    a=list(map(int,input().split(" ")))
    if a[1]-a[0]>=2:
        count+=1
print(count)