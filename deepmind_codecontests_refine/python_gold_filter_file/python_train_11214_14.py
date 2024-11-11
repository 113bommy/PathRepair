n=int(input())
inp = list(map(int,input().split()))
k=min(inp)
a=inp.index(k)
j=sum(inp)-2*k
if(j>0):
    print (1)
    print (a+1)
else:
    print (-1)