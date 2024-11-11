n=int(input())
l=list(map(int,input().split()))
l.sort()
moves=0
for i in range(n):
    if l[i]<0:
        moves+=-(l[i])
        l[i]=0
    elif l[i]>n:
        moves+=l[i]-n
        l[i]=n
for i in range(n):
    moves+=abs(i+1-l[i])
print(moves)    
        