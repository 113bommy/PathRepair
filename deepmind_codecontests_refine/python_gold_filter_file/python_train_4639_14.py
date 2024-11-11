a, b = map(int, input().split())
n = int(input())
y = 10**6

for _ in range(n):
    x, z, v= map(int, input().split())
    y = min(y, ((a-x)**2+(b-z)**2)**(1/2)/v)
print(y)