import sys

def debug(x, table):
    for name, val in table.items():
        if x is val:
            print('DEBUG:{} -> {}'.format(name, val), file=sys.stderr)
            return None

def solve():
    ts, tf, t = map(int, input().split())
    n = int(input())

    if n == 0:
        print(ts)
        return None

    AT = [int(i) for i in input().split()]
    BT = [0]*n

    for i, at in enumerate(AT):
        if i == 0:
            if at > ts:
                print(ts)
                return None
            else:
                BT[i] = ts
        else:
            if at > BT[i - 1] + t and BT[i - 1] + t <= tf:
                print(BT[i - 1] + t)
                return None
            else:
                BT[i] = BT[i - 1] + t

    if BT[n - 1] + 2*t <= tf:
        print(BT[n - 1] + t)
        return None

    min_wait = float('inf')
    ans = None

    for i in range(n):
        if i > 0 and AT[i] == AT[i - 1]:
            continue
        else:
            if BT[i] - (AT[i] - 1) < min_wait and BT[i] + t <= tf:
                min_wait = BT[i] - (AT[i] - 1)
                ans = AT[i] - 1

    print(ans)

if __name__ == '__main__':
    solve()