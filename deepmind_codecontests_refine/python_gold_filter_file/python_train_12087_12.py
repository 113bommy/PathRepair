n = int(input())
l = list(map(int,input().split()))
if l.count(1) == 0:
    print("EASY")
else:
    print("HARD")