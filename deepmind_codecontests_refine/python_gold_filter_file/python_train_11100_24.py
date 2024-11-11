playersCount, winNumber = [int(x) for x in input().split(' ')]
players = [int(x) for x in input().split(' ')]

winsCount = 0
max = 0
for i in range(1, playersCount):
  if players[max] > players[i]:
    winsCount += 1
  else:
    winsCount = 1
    max = i
  
  if winsCount >= winNumber:
    break

print(players[max])