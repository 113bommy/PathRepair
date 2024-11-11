from collections import defaultdict

nDoors = int(input())
pairs = input()

keys = {}
answer = 0
keys = defaultdict(lambda:0, keys)

for x in range(0, 2 * nDoors - 2, 2):
    keys[pairs[x]] += 1
    if keys[pairs[x + 1].lower()] > 0:
        keys[pairs[x + 1].lower()] -= 1
    else:
        answer += 1

print(answer)
