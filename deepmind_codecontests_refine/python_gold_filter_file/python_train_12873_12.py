R = lambda: map(int, input().split())
k, n, s, p = R()
num=0
num=int((int((n-1)/s+1)*k-1)/p+1)
print(num)