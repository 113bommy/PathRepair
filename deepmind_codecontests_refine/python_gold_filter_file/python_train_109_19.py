date = [
    "{0} {1}".format(s,r)
    for s in ('S', 'H', 'C', 'D')
    for r in range(1,13+1)
    ]

count= int(input())
for c in range(count):
    card = input()
    date.remove(card)

for c in date:
    print(c)