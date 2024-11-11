cost = {'q': 9, 'r': 5, 'b': 3, 'n': 3, 'p': 1}
players = [0, 0]
for _ in range(8):
    for c in input():
        players[c.isupper()] += cost.get(c.lower(), 0)

if players[0] > players[1]:
    print('Black')
elif players[0] == players[1]:
    print('Draw')
else:
    print('White')

