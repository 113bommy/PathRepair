cards = [
    "{} {}".format(s, r) for s in ('S', 'H', 'C', 'D') for r in range(1, 13 + 1)
]

count = int(input())


for n in range(count):
    card = input()
    cards.remove(card)


for n in cards:
    print(n)
