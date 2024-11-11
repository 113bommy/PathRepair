n = int(input())
k = int(input())
a = 1
for i in range(n):
    a = min(a*2, a+k)
print(a)