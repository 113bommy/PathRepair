n,m = list(map(int, input().split()))
a = list(map(int, input().split()))
print(max(n-sum(a), -1))
