n = int(input())
a=[]
sum=0
s=0
for i in range(0,n):
        a.append([int(y) for y in input().split()])
        
for i in range(0,n):
    for j in range(0,3):
        sum += a[i][j]
        
    if sum >=2:
        s+=1
    sum=0
print(s)