m,k=map(int,input().split())
for _ in range(k): m=m-1 if m%10 else m//10
print(m)