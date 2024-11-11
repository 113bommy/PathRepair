k=int(input())
a,b=map(int,input().split())
x=b//k
if a<=x*k:
    print("OK")
else:
    print("NG")