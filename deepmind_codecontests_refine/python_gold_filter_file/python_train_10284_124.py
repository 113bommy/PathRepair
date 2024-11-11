k=int(input())
a,b=map(int,input().split())
c=b//k
if a<=k*c:
    print("OK")
else:
    print("NG")