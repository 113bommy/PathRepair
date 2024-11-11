n = int(input())
a,b,c = 0,0,0
for _ in range(n):
    x, y, z = map(int, input().split())
    a,b,c = max(c,b)+x,max(a,c)+y,max(a,b)+z

print(max(a,b,c))


