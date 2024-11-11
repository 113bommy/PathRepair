n, k = map(int, input().split())
towers = list(map(int,input().split()))
operations = []
instability = 10000
operation = 0
for _ in range(k):
    minn, maxx = min(towers),max(towers)
    min_index = towers.index(minn)
    max_index = towers.index(maxx)
    towers[min_index] += 1
    towers[max_index] -= 1
    minn, maxx = min(towers), max(towers)
    val = maxx - minn
    if val <= instability and min_index!=max_index :
        instability = val
        operation += 1
        operations.append((max_index+1,min_index+1))

if instability ==10000:
    instability = 0
print(instability,operation)
for i in operations:
    print(*i)









