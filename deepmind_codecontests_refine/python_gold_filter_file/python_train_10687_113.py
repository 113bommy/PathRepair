n,i=map(int,input().split())
for _ in range(i): n=n-1 if n%10 else n//10
print(n)