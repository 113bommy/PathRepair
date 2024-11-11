lol = input().split(' ')
points = int(lol[0])
first = int(lol[1])
second = int(lol[2])
if (first % points > 0 and second // points == 0) or (second % points > 0 and first // points == 0):
    print(-1)
else:
    print(first // points + second // points)
