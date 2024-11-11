x,y=map(int,input().split())
for _ in range(y): x=x-1 if x%10 else x//10
print(x)