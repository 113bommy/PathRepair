for _ in range(int(input())):
    n=int(input())
    a=list(map(int,input().split()))
    s=input()
    b=[]
    for i,j in zip(a,s):
        b.append([j,i])
    b.sort()
    f=1
    for i in range(n):
        if(b[i][0]=='R' and b[i][1]>(i+1)):
            f=0
            break
        elif(b[i][0]=='B' and b[i][1]<(i+1)):
            f=0
            break
    if(f):
        print('YES')
    else:
        print("NO")