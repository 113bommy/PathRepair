n = int(input())
p = list(map(int, input().split()))

a=[1]
for num in range(1,n):
    a.append(num * 22000)
c=[0]*n

p=list(reversed(p))
new_p=[0]*n

for i in range(n):
    new_p[p[i]-1]=i

for i in range(n):
    c[i]=10**9 - new_p[i]

b=[0]*n
for i in range(n):
    b[i] = c[i]-a[i]

print(*a)
print(*b)