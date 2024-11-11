##n = int(input())
##a = list(map(int, input().split()))
##print(" ".join(map(str, res)))

[n, k] = list(map(int, input().split()))
c = list(map(int, input().split()))
x = list(map(int, input().split()))

res = 0
for i in range(n):
    res += c[i]*c[(i+1)%n]

tot = 0
for i in range(n):
    tot += c[i]

for i in range(k):
    j = x[i]-1
    res += c[j]*(tot-c[j]-c[(j-1+n)%n]-c[(j+1)%n])

ctot = 0
for i in range(k):
    j = x[i]-1
    ctot += c[j]

tmp = 0
for i in range(k):
    j = x[i]-1
    jp = x[(i-1+k)%k]-1
    jn = x[(i+1)%k]-1
    tmp += c[j]*(ctot-c[j])
    if (jp+1)%n == j:
        tmp -= c[j]*c[jp]
    if (jn-1+n)%n == j:
        tmp -= c[j]*c[jn]
tmp = tmp//2
res -= tmp

print(res)