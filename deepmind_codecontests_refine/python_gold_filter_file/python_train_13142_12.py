t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    for i in range(k-1):
        s = str(n)
        n += int(min(s))*int(max(s))
        if min(s) == '0':
            break
    print(n)