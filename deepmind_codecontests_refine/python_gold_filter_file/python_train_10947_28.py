#8:47
INT_MAX=10**18+7
def INPUT():return list(int(i) for i in input().split())
def LIST_1D_ARRAY(n):return [0 for _ in range(n)]
def LIST_2D_ARRAY(m,n):return [[0 for _ in range(n)]for _ in range(m)]
#################################################################################
def cal(n):
    if n==1:
        return 0
    x=0
    y=0
    z=0
    a=n
    while(a%2==0):
        a//=2
        x+=1
    b=n
    while(b%3==0):
        b//=3
        y+=1
    c=n
    while(c%5==0):
        c//=5
        z+=1
    if (2**x)*(3**y)*(5**z)!=n:
        return -1
    else:
        return x+2*y+3*z
for _ in range(int(input())):
    n=int(input())
    print(cal(n))
