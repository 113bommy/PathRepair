n=int(input())
a=[int(input()) for _ in range(n)]
a1=sorted(a)
m=a1[-1]
for i in range(n):
    print(m if m!=a[i] else a1[-2])