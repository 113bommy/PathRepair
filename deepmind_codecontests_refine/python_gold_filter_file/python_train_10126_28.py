t=int(input())
for _ in range(t):
    n=int(input())
    s=""
    for i in range(n):
        s+=input()

    res=[s.count(i)%n for i in set(s)]
    print('YES' if set(res)=={0} else 'NO')
