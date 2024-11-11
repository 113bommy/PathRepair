orders = {
    'North': (2, 6, 3, 4, 1, 5),
    'East': (4, 2, 1, 6, 5, 3),
    'West': (3, 2, 6, 1, 5, 4),
    'South': (5, 1, 3, 4, 6, 2),
    'Right': (1, 3, 5, 2, 4, 6),
    'Left': (1, 4, 2, 5, 3, 6)
}

while True:
    n = int(input())
    if not n:
        break
    dice = list(range(1, 7))
    top = 1

    while n:
        dice = [dice[s - 1] for s in orders[input().strip()]]
        top += dice[0]
        n -= 1
    print(top)