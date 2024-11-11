k = int(input())
a,b = map(int,input().split())
if b//k - (a-1)//k > 0:
    print("OK")
else:
    print("NG")