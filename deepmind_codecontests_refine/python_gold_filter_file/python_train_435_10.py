for i in range(int(input())):
    mine, other = input().split()
    if mine < other:
        print(mine)
        continue
    perfect = ''.join(sorted(mine))
    if (mine == perfect) or (perfect > other):
        print("---")
        continue
    first_problem, second_problem = -1, -1
    for j in range(len(mine)):
        if mine[j] != perfect[j]:
            first_problem = j
            second_problem = mine.rfind(perfect[j], j + 1)
            break
    mine = mine[:first_problem] + perfect[first_problem] +\
           mine[first_problem + 1:second_problem] +\
           mine[first_problem] + mine[second_problem + 1:]
    if mine < other:
        print(mine)
    else:
        print("---")
