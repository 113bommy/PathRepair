n = int(input())
d,x = map(int, input().split())
x+=n
for i in range(n):
    x+= (d-1)//int(input())
print(x)