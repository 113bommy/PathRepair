T = int(input())
for kase in range(T):
    s = input()
    cnt = dict()
    cnt['L'], cnt['R'], cnt['U'], cnt['D'] = 0,0,0,0
    for c in s:
        cnt[c] += 1
    ans = ''
    if min(cnt['L'],cnt['R'])==0:
        if min(cnt['U'],cnt['D'])>=1:
            ans = 'UD'
    elif min(cnt['U'],cnt['D'])==0:
        if min(cnt['L'],cnt['R'])>=1:
            ans = 'LR'
    else:
        h = min(cnt['L'],cnt['R'])
        v = min(cnt['U'],cnt['D'])
        ans = 'U'*v + 'L'*h + 'D'*v + 'R'*h
    print(len(ans))
    print(ans)
