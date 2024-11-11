n, m = map(int, input().split())
aa = list(map(int, input().split()))
print(max(-1,n - sum(aa)))