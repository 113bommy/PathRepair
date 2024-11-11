n,m=map(int,input().split())
for _ in range(m): n=n-1 if n%10 else n//10
print(n)