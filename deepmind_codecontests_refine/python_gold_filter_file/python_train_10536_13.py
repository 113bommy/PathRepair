from collections import defaultdict
t = int(input())

for _ in range(t):
    a = list(input())

    counts = defaultdict(lambda: 0)
    for c in a:
        counts[c] += 1

    ud = min(counts['U'], counts['D'])
    lr = min(counts['L'], counts['R'])
    # print('--------', ud, lr)
    if ud ==  lr == 0:
        print(0)
    elif ud==0:
        print(2)
        print('LR')
    elif lr == 0:
        print(2)
        print('UD')
    else:
        print(2*(ud+lr))
        print('U'*ud + 'R'*lr + 'D'*ud + 'L'*lr)



