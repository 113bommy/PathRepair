want_eat = list(map(int, input().split(' ')))
grapes = list(map(int, input().split(' ')))
grapes[0] -= want_eat[0]
if grapes[0] < 0:
    print('NO')
else:
    all_grapes = sum(grapes) - want_eat[1]
    if all_grapes - grapes[2] < 0 or all_grapes < want_eat[2]:
        print('NO')
    else:
        print('YES')
