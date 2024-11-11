c=1
for _ in range(int(input())):
    a=int(input())
    if(a%2==0):
        print(a//2)
    else:
        print((a+c)//2)
        c*=-1