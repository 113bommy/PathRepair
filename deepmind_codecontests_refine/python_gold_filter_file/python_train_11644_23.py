n, m = map(int, input().split())
print(int((1900*m+100*(n-m))*(2**m)))