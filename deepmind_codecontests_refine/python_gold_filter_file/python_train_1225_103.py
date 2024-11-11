n,k = map(int,input().split())
pi = list(map(int,input().split()))
pi.sort()
print(sum(pi[:k]))