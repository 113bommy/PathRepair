t = int(input())
for i in range(t):
    a = list(map(int,input().split()))
    rx,ry = 0,0
    if a[2]>a[4]:
        rx=1
    if a[3]>a[5]:
        ry=1
        
    if ((a[2]==a[4]) | (a[3]==a[5])):
        print(0)
    else:
        res = min(abs(a[2]-a[4])+(a[0]-a[2])*rx*2,abs(a[3]-a[5])+(a[1]-a[3])*ry*2)
        print(res)