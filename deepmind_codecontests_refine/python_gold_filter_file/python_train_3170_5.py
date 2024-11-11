n = int(input())

max_ct = 0
max_team = None

teams = dict()

for _ in range(n):
    name = input()
    if name not in teams:
        teams[name] = 1
    else:
        teams[name] += 1

    if teams[name] > max_ct:
        max_ct = teams[name]
        max_team = name

print(max_team)
