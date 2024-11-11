n=int(input())
li=list(map(int,input().split()))
if li.count(0)== n:
    print("EASY")
else:
    print("HARD")
