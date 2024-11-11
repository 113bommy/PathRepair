n=int(input())
l=list(map(int,input().split()))
x,y=map(int,input().split())
print(sum(l[x-1:y-1]))