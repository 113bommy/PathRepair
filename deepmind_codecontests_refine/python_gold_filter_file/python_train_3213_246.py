a,b,x=map(int,input().split())
B=b//x
A=a//x

print(B-A+ (a%x == 0))
