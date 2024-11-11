import sys
input = sys.stdin.readline

t = int(input())
for i in range(t):
    n,s,k = map(int, input().split())
    a = set(list(map(int, input().split())))
    sr = s
    sl = s

    ansl = 0
    ansr = 0

    endl = False
    endr = False

    while not endl:
        if sl in a:
            if sl-1 > 0:
                sl -= 1
                ansl += 1
            else:
                endl = True
                ansl = 1001
        else:
            endl = True

    while not endr:
        if sr in a:
            if sr+1 <= n:
                sr += 1
                ansr += 1
            else:
                endr = True
                ansr = 1001
        else:
            endr = True

    ans = min(ansr, ansl)
    print(ans)
