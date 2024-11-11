def test(n):
    if n % 4 == 0:
        return n
    elif n % 4 == 1:
        return 1
    elif n % 4 == 2:
        return n + 1
    else:
        return 0


n = int(input())
s = 0
for i in range(n):
    x, m = map(int, input().split())
    count = 0
    s ^= test(x + m - 1) ^ test(x - 1)

if s == 0:
    print("bolik")
else:
    print("tolik")
