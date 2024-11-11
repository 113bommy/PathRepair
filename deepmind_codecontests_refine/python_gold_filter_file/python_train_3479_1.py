n = int(input())
cards = list(map(int, input().split()))
cards.sort()
stair = []
stair_rev = []
stair.append(cards[0])
cards.pop(0)
a = 0
while a < len(cards):
    if cards[a] > stair[-1]:
        stair.append(cards[a])
        cards.pop(a)
    else:
        a+= 1
tmpmax = stair[-1]
cards.sort(reverse = True)
a = 0
while a < len(cards):
    if cards[a] < tmpmax:
        tmpmax = cards[a]
        stair_rev.append(cards[a])
        cards.pop(a)
    else:
        a+= 1
            
stair += stair_rev
print(len(stair))
s = ''
for d in stair[0:-1]:
    s += str(d)+' '
s += str(stair[-1])
print(s)
