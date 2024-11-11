K = int(input())
A,B = map(int, input().split())

if A<=K*(B//K)<=B:
    print("OK")
else:
    print("NG")