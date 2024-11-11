n=int(input())
arr=list(map(int,input().split()))
if arr.count(1)==0:
    print("EASY") 
else:
    print("HARD")