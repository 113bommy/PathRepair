n = int(input())
t = 0
for i in range(n):
    p, q = map(int,input().split())
    if q - p >= 2:
        t += 1
print(t)