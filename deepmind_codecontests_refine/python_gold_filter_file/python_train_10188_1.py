n=int(input())
c=list(map(int, input().split()))
a=list(range(n,n**2+1,n))
b=a[::-1]
for i in range(n):
    b[c[i]-1]+=i
print(*a)
print(*b)