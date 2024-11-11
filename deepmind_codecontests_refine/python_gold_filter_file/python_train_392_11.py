n=int(input())
a = [int(input()) for i in range(n)]
b = sorted(a)
for i in range(n):
    print(b[-2] if a[i]==b[-1] else b[-1])