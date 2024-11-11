A, B, K = map(int, input().split())
d = [i for i in range(100,0,-1) if (A%i==0 and B%i==0)]
print(d[K-1])
