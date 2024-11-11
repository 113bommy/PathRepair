t = int(input())
classes = []
answer = 0
for i in range(t):
    s = input()
    classes.insert(i, s)
for i in range(7):
    room = 0
    for j in range(len(classes)):
        if int(classes[j][i]) == 1:
            room += 1
    if room > answer:
        answer = room
print(answer)
