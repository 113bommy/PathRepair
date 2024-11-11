F = input()
M = input()
S = input()

player = {F:'F', M:'M', S:'S'}

possible_throws = [['paper', 'rock', 'rock'], ['rock', 'scissors', 'scissors'], ['paper', 'paper', 'scissors']]

possible_wins = ['paper', 'rock', 'scissors']

packets = [F,M,S]
packets.sort()


if packets in possible_throws:
    winner = possible_wins[possible_throws.index(packets)]
    print(player[winner])
else :
    print("?")
