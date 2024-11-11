t = int(input())
tests = [[c for c in input()] for _ in range(t)]

multipliers = [12, 6, 4, 3, 2, 1]
compl = [12 // i for i in multipliers]

for test in tests:
    res = []
    for k, m in enumerate(multipliers):
        for j in range(0, m):
            disp = [e for i, e in enumerate(test[j:]) if i % m == 0 and e == 'X']
            if len(disp) == compl[k]:
                res.append('{}x{}'.format(compl[k], multipliers[k]))
                break
    print(str(len(res)), ' '.join(res))
