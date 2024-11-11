n = int(input())
a = sorted(list(map(int, input().split(' '))))
s = sum(a)

if s % n == 0:
    print(n)
else:
    print(n - 1)
