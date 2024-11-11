n,k=map(int, input().split())
am = n % k
print(min(am,(k-am)))