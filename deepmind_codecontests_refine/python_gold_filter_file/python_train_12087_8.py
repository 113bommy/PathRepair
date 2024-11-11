n=int(input())
l=list(map(int,input().split()))
if l.count(0)==n:
    print("EASY")
else:
    print("HARD")