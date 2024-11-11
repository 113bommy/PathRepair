from collections import Counter
for _ in range(int(input())):
    size = input()
    teams = Counter(map(int,input().split()))
    com = teams.most_common(1)[0][1]
    distinct = len(teams)
    if com - 1 >= distinct: print(distinct)
    else: print(min(com,distinct-1))