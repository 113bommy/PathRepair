n,m=map(int,input().split());c=0;p=m
for i in range(n) :
    s=list(input().split())
    if s[0]=="+" :
        p=p+int(s[1])
    if s[0]=="-" :
        if p>=int(s[1]) :
            p=p-int(s[1])
        else :
            c=c+1
print(p,c)

