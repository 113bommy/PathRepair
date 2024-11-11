n, k=map(int, input().split())
a=list(map(int, input().split()))
x=0
for i in range(n):
    if a[i]<=5-k:
        x+=1
print(x//3)