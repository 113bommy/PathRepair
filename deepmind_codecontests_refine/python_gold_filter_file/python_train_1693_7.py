
t=int(input())

for i in range(t):
    n=int(input())
    ch1=input()
    ch2=input()
    L=[]
    nb=0
    s=""
    for i in range(1,n):
        if ch1[i]!=ch1[i-1]:
            s+=str(i)
            s+=" "
            nb+=1

    if ch1[n-1]!=ch2[n-1]:
        s+=str(n)
        s+=" "
        nb+=1

    for i in range(n-2,-1,-1):
        if ch2[i]!=ch2[i+1]:
            s+=str(i+1)
            s+=" "
            nb+=1
    if ch1!=ch2:
        print(nb,s)
    else:
        print(0)
