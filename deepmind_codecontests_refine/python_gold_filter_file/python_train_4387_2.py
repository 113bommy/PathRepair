table = input()
table = list(table)


hand = input()
hand= list(hand)
k = False
for i in range(0, 14):
    if table[0] == hand[i] or table[1]==hand[i]:
        k = True
if k:
    print("YES")
else:
    print("NO")
