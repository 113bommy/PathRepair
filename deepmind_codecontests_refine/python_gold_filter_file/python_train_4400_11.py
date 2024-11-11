n=int(input())
a=[int(x) for x in input().split()]
for i in range(n):
    print(a.index(i+1)+1,end=" ")
