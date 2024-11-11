length = int(input())
arr = input().split(" ")
arr = list(map(int, arr))
go = True
currentHigh = -1
player =1 


leftMax = 1
rightMax = 1
for i in range(length-1):
    if arr[i]<arr[i+1]:
        leftMax += 1
    else:
        break
for i in range(length-1):
    if arr[-(i+1)]<arr[-(i+2)]:
        rightMax += 1
    else:
        break

def won(player):
    global go
    if player%2 != 0:
        print("Alice")
    else:
        print("Bob")
    go = False


def pick(d):
    global currentHigh, player
    if d=="L":
        if currentHigh>=arr[0]:
            won(player+1)
        currentHigh = arr.pop(0)
    else:
        if currentHigh>= arr[-1]:
            won(player+1)
        currentHigh = arr.pop(-1)
    player +=1


while go:
    left = arr[0]
    right = arr[-1]
    if left == right:
        if leftMax%2 != 0 or rightMax%2 !=0:
            won(player)
        else:
            won(player+1)

    if left > right:
        if leftMax%2 != 0:
            won(player)
        else:
            rightMax -= 1
            pick('R')
    if right > left:
        if rightMax%2 != 0:
            won(player)
        else:
            leftMax -=1
            pick("L")




# if leftMax%2 != 0 or rightMax%2 != 0 or length == 1:
#     print("Alice")
# else:
#     print("Bob")




