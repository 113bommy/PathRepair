n = int(input())
a, b = map(int, input().split())
if b//n > (a-1)//n:
    print("OK")
else:
    print("NG")
