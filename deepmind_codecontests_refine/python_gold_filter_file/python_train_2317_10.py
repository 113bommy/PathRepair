T = int(input())

def solve():
    N = int(input())
    A = list(map(int,input().split()))
    evens = []
    odds = []
    for i,a in enumerate(A):
        if a % 2 == 0:
            evens.append(i)
        else:
            odds.append(i)
    if len(evens) % 2 == 0:
        if len(evens) == 0:
            odds.pop(0)
            odds.pop(0)
        else:
            evens.pop(0)
            evens.pop(0)
    else:
        evens.pop(0)
        odds.pop(0)

#    print(evens)
#    print(odds)

    for i in range(len(evens)//2):
        print("%d %d" % (evens[2*i]+1, evens[2*i+1]+1))
    for i in range(len(odds)//2):
        print("%d %d" % (odds[2*i]+1, odds[2*i+1]+1))

for _ in range(T):
    solve()
