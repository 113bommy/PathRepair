



a,b =map(int,input().split())



t=0
r=0


while a:
    t+=a
    r+=a
    a,r = (r//b,r%b)

print(t)
