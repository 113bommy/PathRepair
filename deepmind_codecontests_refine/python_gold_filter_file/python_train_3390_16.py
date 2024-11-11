a,b=map(int,input().split())
k='CYM'
flag=0
for i in range(a):
    ls=input().split()
    for j in ls:
        if j in k:
            flag=1
            break
if(flag==0):
    print("#Black&White")
else:
    print("#Color")
         