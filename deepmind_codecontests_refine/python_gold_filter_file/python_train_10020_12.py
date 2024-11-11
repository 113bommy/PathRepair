import sys,math 
Tests=int(input())
for _ in range(Tests):
    n,x=map(int,sys.stdin.readline().split())
    ans=0
    deg=0
    for i in range(n-1):
        a,b=map(int,sys.stdin.readline().split())
        if a==x or b==x:
            deg+=1 
    if deg<=1:
        print("Ayush")
    else:
        if((n-2)%2==1):
            print("Ashish")
        else:
            print("Ayush")