n,m = list(map(int, input().split()))
a = list(map(int, input().split()))
ret = [0]*n
a.sort()
even = a[0]
odd = 0
mult = [0]*m
mult[0] = a[0]
ret[0] = a[0]
for i in range(1,n):
    mult[i%m] += a[i]
    ret[i] = ret[i-1] + mult[i%m]
print(*ret)