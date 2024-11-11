N = int(input())
n = 0
if not N%2:
    s = 5
    N = N//2
    while N>=s:
        n += N//s
        s *= 5
print(n)
