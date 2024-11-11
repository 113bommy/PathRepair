N, K = map(int,input().split())
s = list(map(int,input().split()))
s.sort()
print(sum(s[:K]))