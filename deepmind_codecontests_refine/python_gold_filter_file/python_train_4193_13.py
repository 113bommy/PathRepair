''' 1391b Fix you '''
R = lambda : list(map(int,input().split()))
for _ in range(int(input())):
    n,m = R(); lug = []; ch = 0
    for _1 in range(n):
        temp = [*input()]
        if temp[-1] == 'R':
            ch+=1
        lug.append(temp)
    ch+=lug[-1].count('D')
    print(ch)
