d=int(input())
m=int(input())
a=list(map(int,input().split()))[:m]
count=0
for i in range(len(a)-1):
    count+=d-a[i]
print(count)
    
