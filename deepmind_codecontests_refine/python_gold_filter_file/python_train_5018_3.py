n=int(input())
for i in range(n):
    a,b=map(int,input().split())
    c=abs(a-b)
    res=c//5
    c%=5
    res+=c//2
    c%=2
    res+=c
    print(res)