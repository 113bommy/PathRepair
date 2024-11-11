from copy import deepcopy

t = int(input())
for _ in range(t):
    n = int(input())
    arr = list(map(int,list(input())))

    narr = deepcopy(arr)
    narr.sort()
    color = [0]*n
    no = 1
    i,j = 0,0
    while i<n:
        while j<n:
            if i==n:
                break
            if arr[j]==narr[i] and color[j]==0:
                color[j]=no
                i+=1
            j+=1
        no+=1
        if no==3:
            break
        j = 0

    #print(color)
    if 0 in color:
        print('-')
    else:
        print(''.join(list(map(str,color))))
