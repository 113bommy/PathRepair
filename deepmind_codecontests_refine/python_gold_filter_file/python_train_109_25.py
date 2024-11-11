cards = []
for i in ['S','H','C','D']:
    for j in range(1, 14):
        cards.append(i + " " + str(j))
N = int(input())
for i in range(N):
    cards.remove(input())

for i in range(len(cards)):
    print (cards[i])

