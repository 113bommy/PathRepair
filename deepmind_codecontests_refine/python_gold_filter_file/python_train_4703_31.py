from sys import stdin,stdout
t=int(stdin.readline().rstrip())
while t>0:
    a,b=map(int,stdin.readline().split())
    stdout.write(str(b*2)+"\n")
    t-=1