n,a,b = map(int, input().split())

print(int(n/(a+b))*a + min(a,(n%(a+b))))