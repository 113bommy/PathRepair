n = int(input())
games = []
for i in range(n):
    games.append(input().split())

for i in range(n):
    temp = games[i]
    temp0 = int(temp[0])
    temp1 = int(temp[1])
    if temp0 == temp1:
        print(0)
        continue
    if temp0 < temp1:
        if (temp1 - temp0) % 2 == 0:
            print(2)
        else: print(1)
    else:
        if (temp0 - temp1) % 2 == 0:
            print(1)
        else: print(2)