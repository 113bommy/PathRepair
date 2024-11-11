

n, x = map(int, input().split())

table = {}

for a in map(int, input().split()):
    if a in table:
        table[a] += 1
    else:
        table[a] = 1

ans = 0    
for i in table.keys():
    if table[i] > 0:
        if i ^ x in table:
            if i == i ^ x:
                ans += table[i] * (table[i] - 1) // 2
            else:
                ans += table[i] * table[i ^ x]
            table[i ^ x] = 0

print(ans)