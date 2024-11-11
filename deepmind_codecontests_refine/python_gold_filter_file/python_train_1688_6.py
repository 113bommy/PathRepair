n=int(input())
for i in range(n):
    s=[x for x in input()]
    t=[x for x in input()]
    n,m=len(s),len(t)
    bo=0
    for i in range(0,m-n+2):
        if(sorted(s)==sorted(t[i:i+n])):
            print("YES")
            bo=1
            break
    if(not bo):
        print("NO")
