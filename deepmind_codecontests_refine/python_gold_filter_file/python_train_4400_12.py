n=int(input())
p=[int(x) for x in input().split()]
for i in range (0,n):
    print(p.index(i+1)+1,end=" ")