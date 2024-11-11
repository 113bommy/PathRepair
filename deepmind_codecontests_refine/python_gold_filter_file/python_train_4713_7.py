from sys import stdin, stdout
t=int(stdin.readline())
for _ in range(t):
    arr=stdin.readline()
    arr=arr[:len(arr)-1]
    w=int(stdin.readline())
    n=len(arr)
    pc=[1]*n
    counter=0
    for i in range(n):

        if counter==1:
            break
        if arr[i]=='0':
            if i-w>=0:
                pc[i-w]=0
            if i+w<n:
                pc[i+w]=0
    nc=[i for i in pc]
    for i in range(n):
        c1,c2=0,0
        if i+w<n and i-w>=0 and pc[i+w]==1 and pc[i-w]==1:
            nc[i]=1
        elif (i+w<n and pc[i+w]==1) or (i-w>=0 and pc[i-w]==1):
            nc[i]=1
        else:
            nc[i]=0
        if int(arr[i])!=nc[i]:
            print(-1)
            counter=1
            break
    if counter==0:
        for i in range(n):
            print(pc[i],end='')

    print()



