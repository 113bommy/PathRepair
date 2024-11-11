k=int(input())
a,b=map(int,input().split())

if b//k!=(a-1)//k:
    print("OK")
else:
    print("NG")