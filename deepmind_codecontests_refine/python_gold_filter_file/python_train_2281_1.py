first = input().split()
n = int(first[0])
r = int(first[1])
while n != 0 or r != 0:
    i = 0
    card = list(range(1,n+1))[::-1]
    while i < r:
        sh = input().split()
        p, c = list(map(int,sh))
        card = card[p-1:p+c-1] + card[:p-1] + card[p+c-1:]
        i = i + 1
    print(card[0])
    next = input().split()
    n, r = list(map(int,next))