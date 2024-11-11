n, l = map(int, input().split())
a = sorted([l + i for i in range(n)], key=abs)
print(sum(a[1:]))

