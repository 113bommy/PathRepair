k,a,b=map(int,input().split(' '))
s=input()
l=len(s)
if(l<k*a or l>k*b):
    print("No solution")
else:
    n1=l//k
    n2=n1+1
    n3=k-(l%k)
    n4=l%k
    cur=0
    for i in range(n3):
        print(s[cur:cur+n1])
        cur+=n1
    for i in range(n4):
        print(s[cur:cur+n2])
        cur+=n2
