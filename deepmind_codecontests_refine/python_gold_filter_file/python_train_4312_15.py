n= int(input())
l= list(map(int, input().split()))
ans='no'
for i in range(0, n-1):
    for j in range(0, n-1):
        x1,x2= sorted([l[i], l[i+1]])
        x3,x4= sorted([l[j], l[j+1]])
        if x1<x3<x2 and x3<x2<x4:
            ans='yes'
 
print(ans)