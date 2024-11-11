for _ in range(int(input())):
    n=int(input())
    l=[]
    for i in range(n):
        l.append(list(input()))
    x=[]
    for j in range(n):
        for k in range(n):
            if l[j][k]=='*':
                x.append([j,k])
    
    if x[0][0]==x[1][0]:
        if x[0][0]==0:
            l[1][x[0][1]]='*'
            l[1][x[1][1]]='*'
        elif x[0][0]==n-1:
            l[n-2][x[0][1]]='*'
            l[n-2][x[1][1]]='*'
        else:
            l[x[0][0]+1][x[0][1]]='*'
            l[x[0][0]+1][x[1][1]]='*'

    elif x[0][1]==x[1][1]:
        if x[0][1]==0:
            l[x[0][0]][1]='*'
            l[x[1][0]][1]='*'
        elif x[0][1]==n-1:
            l[x[0][0]][n-2]='*'
            l[x[1][0]][n-2]='*'
        else:
        
            l[x[0][0]][x[0][1]+1]='*'
            l[x[1][0]][x[0][1]+1]='*'
    else:
        # if x[0][1]==0:
        #     l[x[0][0]][1]='*'
        #     l[x[0][0]][1]='*'
        # elif x[0][1]==n-1:
        #     l[x[0][0][n-2]='*'
        #     l[x[0][0]][n-2]='*'
        # else:
        
        l[x[0][0]][x[1][1]]='*'
        l[x[1][0]][x[0][1]]='*'
    for ss in range(n):
        for sss in range(n):
            print(l[ss][sss],end='')
        print()








