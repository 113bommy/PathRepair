import sys
input = sys.stdin.readline
for _ in range(int(input())):
    n = int(input())
    l = list(map(int,input().split()))
    l.sort()
    for i in range(1,(n//2)+1):
        sys.stdout.write(str(l[i])+" "+str(l[0])+"\n")

