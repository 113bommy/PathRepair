#!usr/bin/env python3

def go ():
    l1,r1,l2,r2,k = tuple(map(lambda x: int(x), input().split()))
    if (l1 > r2) or (l2 > r1):
        print (0)
        return

    l = min(l2, l1) + abs(l2-l1)
    r = max(r2,r1) - abs(r2-r1)
    if (k >= l) and (k <= r):
        print(r - l)
    else:
        print(r - l + 1)

if __name__ == "__main__":
    go()
