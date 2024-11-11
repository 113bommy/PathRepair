def getInverts(arr,N):
    inverts = []
    if arr[0][1] == arr[1][0]:
        if arr[-1][-2] == arr[0][1]:
            inverts.append([N-1,N-2])
        if arr[-2][-1] == arr[0][1]:
            inverts.append([N-2,N-1])
    else:
        if arr[-1][-2] == arr[-2][-1]:
            if arr[0][1] == arr[-1][-2]:
                inverts.append([0,1])
            else:
                inverts.append([1,0])
        else:
            if arr[0][1] == arr[-1][-2]:
                inverts.append([0,1])
                inverts.append([N-2,N-1])
            else:
                inverts.append([1,0])
                inverts.append([N-2,N-1])
    return inverts



T = int(input())
for t in range(T):
    N = int(input())
    arr = []
    for n in range(N):
        arr.append(list(input()))
    inverts = getInverts(arr,N)
    print(len(inverts))
    for i in inverts:
        print(i[0]+1,i[1]+1)
