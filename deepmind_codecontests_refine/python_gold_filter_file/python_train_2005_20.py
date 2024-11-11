def stringflip(l,s):
    news=""
    for i in range(l):
        if s[l-i-1]=="0":
            news+="1"
        else:
            news+="0"
    if l!=n:
        news+=s[l:]
    return news

def flip(n,a,b):
    if a==b:
        print(0)
        return
    #a to b
    moves=0
    array=[]
    for i in range(n):
        if a[0]==b[n-i-1]:
            array.append(1)

            array.append(n-i)
            moves+=2
            stringflip(1,a)
            a=stringflip(n-i,a)
        else:
            array.append(n-i)
            moves+=1
            a=stringflip(n-i,a)

    print(moves,end=" ")
    for x in array:
        print(x,end=" ")
    print()
    return

t=int(input())
a=[]
for j in range(t):
    n=int(input())
    d=input()
    e=input()
    a.append([n,d,e])
for x in a:
    flip(*x)