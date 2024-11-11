ignore=input()
lis=list(map(int,input().split()))
n=0
while lis!=[] :
    a=lis.pop(0)
    while a!=0:
        if lis==[]:
            break
        elif lis[-1]>a:
            lis[-1]=lis[-1]-a
            break
        else:
            a=a-lis[-1]
            lis.pop()
    n+=1
print(n)
