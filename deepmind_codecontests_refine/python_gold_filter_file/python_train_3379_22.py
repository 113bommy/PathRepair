def toset(player):
    return list(set(player))
n=int(input())
player1=[int(i) for i in input().split()]
player1.remove(player1[0])
player2=[int(i) for i in input().split()]
player2.remove(player2[0])
lvl=[]
for i in range(1,n+1):
    lvl.append(i)
player=[]
player=player1+player2
players=toset(player)
players.sort()
if(players==lvl):
    print("I become the guy.")
else:
    print("Oh, my keyboard!")