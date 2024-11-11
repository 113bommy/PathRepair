while True:
    (n, r) = [int(x) for x in input().split()]
    if n==0 and r==0:
        exit()
    cards = [n-i for i in range(n)]
    for _ in range(r):
        (p, c) = [int(x) for x in input().split()]
        cards = cards[p-1:p-1+c] + cards[:p-1] + cards[p-1+c:]
    print(cards[0])