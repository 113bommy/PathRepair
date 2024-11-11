t = int(input())
for i in range(t):
    n = int(input())
    s = bin(n)
    ans = 2 ** (s.count('1'))
    print(ans if n != 0 else 1)
    