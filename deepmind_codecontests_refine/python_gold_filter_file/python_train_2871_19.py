n = int(input())
a = [int(x) for x in input().split()]

for i in range(0,(n+1)//2,2):
    a[i],a[n-i-1] = a[n-i-1],a[i]

for i in range(n-1):
    print(a[i],end=" ")
print(a[n-1],end="")