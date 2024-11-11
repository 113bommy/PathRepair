n = int(input())
l = list(map(int,input().split()))
print(n+1)
print(1,n,n*4)
for j in range(n):
    print(2,j+1,l[j]+4*n-j)