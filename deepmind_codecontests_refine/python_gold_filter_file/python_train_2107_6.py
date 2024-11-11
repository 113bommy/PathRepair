n = int(input())
for i in range(n):
    input()
    lst = list(map(int,input().split()))
    sol = []
    sol.append(1)
    col = 1
    modify = False
    if lst[-1] == lst[1]:
        modify = True
        lst = [lst[-1]] + lst[:-1]

    pos = -1
    for i in range(1, len(lst)):
        if lst[i] != lst[i-1]:
            if col == 1:
                col = 2
            else:
                col = 1
        else:
            pos = i
        sol.append(col)

    if lst[0] != lst[-1] and sol[0] == sol[-1]:
        if pos == -1:
            sol[-1]=3
        else:
            for i in range(pos, len(lst)):
                if sol[i] == 1:
                    sol[i] = 2
                else:
                    sol[i] = 1

    if modify:
        sol = sol[1:] + [sol[0]]


    print(max(sol))
    print(*sol)
