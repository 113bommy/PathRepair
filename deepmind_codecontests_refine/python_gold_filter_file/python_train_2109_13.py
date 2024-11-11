def accuratelee():
    n=int(input())
    s=input()
    x=".".join(s)
    p=x.split(".")
    y=sorted(p)
    if p==y:
        print(s)
        return
    else:
        c,d=0,0
        for i in s:
            if i=="1":
                break
            c=c+1
        for i in s[::-1]:
            if i=="0":
                break
            d=d+1
        print("0"*(c+1)+"1"*d)
        return
for i in range(int(input())):
    accuratelee()