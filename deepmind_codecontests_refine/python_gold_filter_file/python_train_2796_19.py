N,x=map(int,input().split())

ANS=[]
for i in range(1,2*N):
    ANS.append(i)

if x==1 or x==(N*2-1):
    print("No")
else:
    print("Yes")
    if x==N:
        for j in range(len(ANS)):
            print(ANS[j])
    elif x<N:
        for j in range(1,N):
            if ANS[j]==x:
                pass
            else:
                print(ANS[j])
        print(1)
        print(x)
        for k in range(N,N*2-1):
            print(ANS[k])
    elif x>N:
        for j in range(N-1):
            print(ANS[j])
        print(x)
        print(N*2-1)
        for k in range(N-1,N*2-2):
            if ANS[k]==x:
                pass
            else:
                print(ANS[k])
    