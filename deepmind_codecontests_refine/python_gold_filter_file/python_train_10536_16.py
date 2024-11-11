q=int(input().strip())
for a0 in range(q):
    s=input().strip()
    arr=[]
    c_L,c_R,c_D,c_U=0,0,0,0
    for i in s:
        arr.append(i)
        if i=='L':
            c_L=c_L+1
        elif i=='R':
            c_R = c_R + 1
        elif i=='D':
            c_D = c_D + 1
        elif i=='U':
            c_U = c_U + 1
    y=min(c_D,c_U)
    x=min(c_L,c_R)
    if x==0 and y==0:
        print("0")
    elif x==0:
        print('2')
        print('UD')
    elif y==0:
        print('2')
        print('LR')
    else:
        print(2*(x+y))
        print(x*'L'+y*'D'+x*'R'+y*'U')