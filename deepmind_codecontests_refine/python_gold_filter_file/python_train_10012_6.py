"""T=int(input())
for _ in range(0,T):
    N=int(input())
    a,b=map(int,input().split())
    s=input()
    s=[int(x) for x in input().split()]
    for i in range(0,len(s)):
        a,b=map(int,input().split())"""


T=int(input())
for _ in range(0,T):
    N=int(input())
    s=[int(x) for x in input().split()]
    s.sort()
    if(len(s)<3):
        print(0)
    elif(min(s[-1],s[-2])<2):
        print(0)
    else:
        base=min(s[-1],s[-2])-1
        ans=min(base,len(s)-2)
        print(ans)
