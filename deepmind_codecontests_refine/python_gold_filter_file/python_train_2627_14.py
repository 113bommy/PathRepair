n = int(input())
l = list(map(int,input().split()))
temp=0
a=[l[0]]
print(l[0],end=" ")
for i in range(1,n):
    a.append(l[i] + max(temp,a[i-1]))
    print(a[i],end=" ")
    temp = max(temp,a[i-1])
    
    
    