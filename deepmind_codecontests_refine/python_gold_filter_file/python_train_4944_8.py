__author__ = 'trunghieu11'
n = int(input())
first = list(map(int, input().split()))[1:]
second = list(map(int, input().split()))[1:]
first.reverse()
second.reverse()
round = 0
while (round < 10000):
    if len(first) * len(second) == 0:
        break
    fCard = first.pop()
    sCard = second.pop()
    if fCard > sCard:
        first.insert(0, sCard)
        first.insert(0, fCard)
    else:
        second.insert(0, fCard)
        second.insert(0, sCard)
    round += 1
if len(first) == 0:
    print(round, 2)
elif len(second) == 0:
    print(round, 1)
else:
    print(-1)