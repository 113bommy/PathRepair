q=0
for i in range(int(input())):
    a,b,c=map(int,input().split())
    q=min(c//2,b)
    q+=min(a,(b-q)//2)
    print(3*q)