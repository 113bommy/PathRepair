a,b=map(int,input().split())
for _ in range(b):a=a-1 if a%10 else a//10
print(a)