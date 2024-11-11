k, a, b = map(int, input().split())

s = input()

m = a*k

M = b*k

tot = len(s) - m
current = 0
if m <= len(s) <= M:
    for _ in range(k):
        print(s[current:current+a + min(tot, b-a)])
        current += a + min(tot, b-a)
        tot = max(tot-b+a, 0)


else:
    print("No solution")