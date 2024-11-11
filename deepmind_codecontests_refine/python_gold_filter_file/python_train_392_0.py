n=int(input())
a = [int(input()) for i in range(n)]
b = sorted(a)
for i in a:
    print(b[-2] if i==b[-1] else b[-1])