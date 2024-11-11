import sys
input=sys.stdin.readline

t=int(input())
for you in range(t):
    n=int(input())
    l=input().split()
    li=[int(i) for i in l]

    li.sort()
    for i in range(1,1+(n//2)):
        print(li[i],li[0])
