n = int(input())
a = [int(x) for x in input().split()]
a = sorted(a)
b = a[::2] + a[1::2][::-1]
print(*b)