t=int(input())
while t>0:
    t-=1
    n,c1,c2,h=map(int,input().split())
    s=input()
    a=s.count("0")
    b=s.count("1")
    c=a*c1+b*c2
    d=a*h+(n)*c2
    e=b*h+n*c1
    print(min(c,d,e))