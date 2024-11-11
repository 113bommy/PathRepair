a=int(input())
count=0
for i in range(a):
    a=list(map(int,input().split()))
    if a[1]-a[0] >= 2:
        count+=1
print(count)