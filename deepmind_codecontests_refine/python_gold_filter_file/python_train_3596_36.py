n, iceCreamPacks = map(int, input().split())
queue = []
for i in range(n):
    queue.append(input().replace(' ', ''))
queue = [int(x) for x in queue]

distressed = 0

for person in queue:
    if person > 0:
        iceCreamPacks += person
    else:
        if iceCreamPacks >= abs(person):
            iceCreamPacks = iceCreamPacks + person
        else:
            distressed += 1

print(iceCreamPacks, distressed)