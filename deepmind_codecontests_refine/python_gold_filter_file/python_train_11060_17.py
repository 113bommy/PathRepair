t=int(input())
for i in range(t):
    n=int(input())
    if (n//2)%2==1:print("NO")
    else:
        L=[]
        for i in range(n//4):
            L+=[2+6*i,4+6*i]
        for i in range(n//4):
            L+=[1+6*i,5+6*i]
        print("YES")
        print(*L)