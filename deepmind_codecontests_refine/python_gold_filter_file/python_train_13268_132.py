n = int(input())

roomn = 0
for i in range(n):
        rooms = input()
        rooms = rooms.split(" ")
        if int(rooms[0])<=int(rooms[1])-2:
                roomn+=1

print(roomn)
