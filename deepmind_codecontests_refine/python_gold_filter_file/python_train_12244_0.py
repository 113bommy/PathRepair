balls, friends = map(int, input().split())
colors = str(input())
result = 'YES'
database = {}

for i in colors:
    database[i] = database.get(i, 0) + 1
    if database[i] > friends:
        result = 'NO'
        break

print(result)