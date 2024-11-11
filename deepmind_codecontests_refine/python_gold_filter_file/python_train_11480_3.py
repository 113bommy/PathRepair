from sys import stdin
input=lambda:stdin.readline().strip()
for _ in range(int(input())):
    n=int(input())
    lst=[int(i) for i in input().split()]
    nd=0
    for i in range(1,n):
        nd+=max([0,lst[i-1]-lst[i]])
    print(nd)
