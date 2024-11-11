team1 = input()
team2 = input()
fouls = int(input())

warn1 = [False] * 100
warn2 = [False] * 100
out1 = [False] * 100
out2 = [False] * 100

warns = []

for i in range(fouls):
    a, b, c, d = map(str, input().split(' '))
    a, c = int(a), int(c)
    if b == 'a' and d == 'r' and out2[c] == False:
        warns.append([team2, c, a])
        out2[c] = True
    elif b == 'h' and d == 'r' and out1[c] == False:
        warns.append([team1, c, a])
        out1[c] = True
    elif b == 'a' and d == 'y' and warn2[c] and out2[c] == False:
        warns.append([team2, c, a])
        out2[c] = True
    elif b == 'a' and d == 'y' and not warn2[c]:
        warn2[c] = True
    elif b == 'h' and d == 'y' and warn1[c] and out1[c] == False:
        warns.append([team1, c, a])
        out1[c] = True
    elif b == 'h' and d == 'y' and not warn1[c]:
        warn1[c] = True
warns.sort(key = lambda x:x[2])
for a in warns:
    print(' '.join([str(x) for x in a]))
