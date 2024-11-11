n = int(input())
directions = list(input())
cordinates = list(map(int, input().split()))

distance = 1000000000000

for i in range(0,n):
    if i < n and i+1 < n  and directions[i] == 'R' and directions[i+1] == 'L':
        if cordinates[i+1] - cordinates[i] < distance:
            distance = cordinates[i+1] - cordinates[i]

if distance == 1000000000000:
    print(-1)
else:
    print(distance//2)
