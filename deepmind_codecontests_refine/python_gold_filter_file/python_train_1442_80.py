r,g,b=map(int, input().split())
print(["NO","YES"][(g*10+b)%4==0])