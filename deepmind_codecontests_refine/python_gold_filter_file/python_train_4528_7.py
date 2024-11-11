n = int(input())
badges = list(map(int, input().split()))

counter = [0 for i in range(6005)]

for b in badges:
    counter[b] += 1

cost = 0

for i in range(len(counter)):
    if counter[i] > 1:
        for j in range(i+1, len(counter)):
            if counter[j] == 0:
                counter[j] = counter[i] - 1
                cost += ((counter[i] - 1) * (j - i))
                counter[i] = 1

print(cost)
