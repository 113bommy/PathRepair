n = int(input())

result = {}
result1 = {}
result2 = {}
test = []
max1 = 0

for i in range(0, n):
    name, scores = map(str, input().split())
    score = int(scores)
    if name in result:
        result[name] += score
    else:
        result[name] = score
    test.append((name, score))

max1 = max(result.items(), key=lambda d: d[1])[1]

for key in result:
    if result[key] == max1:
        result1[key] = max1

for temp in test:
    if temp[0] in result2:
        result2[temp[0]] += temp[1]
    else:
        result2[temp[0]] = temp[1]
    if result2[temp[0]] >= max1 and temp[0] in result1:
        print(temp[0])
        break