n = int(input())
k = int(input())
a = 1
for _ in range(n):
    a = min(a+k, a*2)
print(a)
