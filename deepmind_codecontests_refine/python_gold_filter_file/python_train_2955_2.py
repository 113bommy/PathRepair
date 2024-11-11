import sys
input=sys.stdin.readline
n=int(input())
l=input().split()
li=[int(i) for i in l]
l=[]
for i in range(n):
    if(l==[] or l[-1][0]!=li[i]):
        l.append((li[i],i))
z=len(l)
poss=0
for i in range(1,z-1):
    if(l[i][0]>l[i-1][0] and l[i][0]>l[i+1][0]):
        poss=1
        print(3)
        print(l[i-1][1]+1,l[i][1]+1,l[i+1][1]+1)
        quit()
    if(l[i][0]<l[i-1][0] and l[i][0]<l[i+1][0]):
        print(3)
        print(l[i-1][1]+1,l[i][1]+1,l[i+1][1]+1)
        quit()
print(0)
