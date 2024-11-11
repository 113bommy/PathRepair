n=int(input())
s=[]
if (n%2!=0):
    print(-1)

else :
    for i in range (1,n+1) :
        s.append(i)
    s.reverse()
    print(" ".join(map(str,s)))