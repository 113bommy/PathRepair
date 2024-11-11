N,K = map(int, input().split())
p = N%K
print(min(p, abs(K-p)))