c=[]
for i in range(int(input())):
    a,b=map(int,input().split())
    if a<b:
        if a%2==0 and b%2==0 or a%2==1 and b%2==1:
            c.append("2")
        if a%2==1 and b%2==0 or a%2==0 and b%2==1:
            c.append("1")
    if a>b:
        if a%2==0 and b%2==0 or a%2==1 and b%2==1:
            c.append("1")
        if a%2==1 and b%2==0 or  a%2==0 and b%2==1:
            c.append("2")
    if a==b:
        c.append("0")
for i in c:
    print(i)