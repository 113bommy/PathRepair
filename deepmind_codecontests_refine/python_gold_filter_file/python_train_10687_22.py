s,p=map(int,input().split())
for _ in range(p): s=s-1 if s%10 else s//10
print(s)