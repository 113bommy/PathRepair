while True:
    N = int(input())
    if N == 0:
        break
    
    first_group_menbers = set(input()[:-1].split(":")[1].split(","))
    d = {}
    for i in range(N-1):
        group, members = input()[:-1].split(":")
        d[group] = set(members.split(","))
        
    for i in range(N-2):
        for group, members in d.items():
            if group in first_group_menbers:
                first_group_menbers.remove(group)
                for m in members:
                    first_group_menbers.add(m)
    
    print(len(first_group_menbers))