A, B, K = map(int, input().split())
ns = [i for i in range(1, 101) if A%i==0 and B%i == 0]
print(sorted(ns, reverse=True)[K-1])
