import collections

a_name = input()
b_name = input()
n = int(input())
players = [collections.Counter() for i in range(2)]
for i in range(n):
    t, team, player, color = input().split()
    team = 0 if team == 'h' else 1
    player = int(player)
    if color == 'y' and players[team][player] == 0:
        players[team][player] = 1
    elif color == 'r' and 0 <= players[team][player] <= 1 or players[team][player] == 1:
        players[team][player] = 2
        print(a_name if team == 0 else b_name, player, t)

