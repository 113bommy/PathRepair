n = int(input())
p = []
for i in range(n):
    a, b = map(int, input().split())
    for j in range(a, b + 1):
        p.append(n - i)
        
print(p[int(input()) - 1])