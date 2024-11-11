n=int(input())
l=list(map(int,input().split()))
a,b=map(int,input().split())
print(sum(l[(a-1):(b-1)]))