from sys import stdout as o
for i in range(int(input())):
    a,b=map(int,input().split())
    o.write(str(a^b)+"\n")