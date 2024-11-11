x=int(input())
d=list(map(int,input().split()))
l=list(map(int,input().split()))
if(sum(d)>=sum(l)):
    print("Yes")
else:
    print("No")