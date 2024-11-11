t=int(input())
for _ in range(t):
    a,b,c=map(int,input().split())
    temp=a*1+b*2+c*3
    if(temp%2==0):
        print("0")
    else:
        print("1")