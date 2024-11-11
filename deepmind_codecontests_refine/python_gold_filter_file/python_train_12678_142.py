n,a,b = map(int, input().split())
ab=a+b
print(n//ab*a + min(n-n//ab*(ab),a))