n = int(input())
x = 0
for i in range(n):
    a,b = map(int,input().split())
    if a+1 < b :
        x += 1
print(x)