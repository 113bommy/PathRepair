n=int(input())
c=0
d=0
for _ in range(n):
    x,y,z=map(int,input().split())
    a=list(map(int,input().split()))
    b=list(map(int,input().split()))
    for i in range(len(a)):
        c=max(a)
    for i in range(len(b)):
        d=max(b)
    if c>d:
       ab="YES"
    else:
       ab="NO"
    print(ab)      
