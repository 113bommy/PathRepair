import sys

T = int(sys.stdin.readline())
for _ in range(T):
    n = int(sys.stdin.readline())
    if n <= 3:
        print(-1)
        continue
    result = []
    odd = n - (not n%2)
    even = n - n%2
    while odd >= 1:
        result.append(odd)
        odd -= 2
    result.append(4)
    result.append(2)
    i = 6
    while i <= even:
        result.append(i) 
        i+=2
    print(*result)