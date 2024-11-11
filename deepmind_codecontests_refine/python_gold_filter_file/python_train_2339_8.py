priority = 'rsp'
players = 'FMS'

moves = [input()[0] for _ in range(3)]

if len(set(moves)) in [1, 3]:
    print('?')
else:
    for i in range(3):
        if moves.count(moves[i]) == 1:
            if priority[(priority.index(moves[i]) + 1) % 3] == moves[(i + 1) % 3]:
                print(players[i])
            else:
                print('?')
            break
