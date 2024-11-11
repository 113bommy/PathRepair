t=int(input())
for i in range(t):
    n=int(input())
    str1=""
    for i in range(n):
        str=input()
        str=str1+str
        str1=str
        d={}
    for i in str1:
        k=d.keys()
        if i in k:
            d[i]+=1
        else:
            d[i]=1
    x="YES"
    for j in d.values():
        if j%n!=0:
            x="NO"
    print(x)