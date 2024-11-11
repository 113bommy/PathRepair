a = int(input())
b = int(input())
n=1
for i in range(a):
    n=min(n*2, n+b)
print(n)