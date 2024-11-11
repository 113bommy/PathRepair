count = int(input())
cards = []
for i in range(count):
    cards.append(input())
capitals = "SHCD"
for j in capitals:
    for k in range(1,14):
        if ((j + " " + str(k)) in cards) == False:
            print(j + " " + str(k))
