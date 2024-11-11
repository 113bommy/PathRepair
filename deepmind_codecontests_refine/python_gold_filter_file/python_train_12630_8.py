a=int(input())
for i in range(a):
    b=int(input())
    c=input().split()
    d=0
    for i in range(b*2):
        if(int(c[i])%2==1):
            d+=1
    if(d==b):
        print("Yes")
    else:
        print("No")
