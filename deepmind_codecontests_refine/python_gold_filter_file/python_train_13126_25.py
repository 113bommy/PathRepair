n=int(input())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
if(sum(b)<=sum(a)):
    print("Yes")
else:
    print("No")
