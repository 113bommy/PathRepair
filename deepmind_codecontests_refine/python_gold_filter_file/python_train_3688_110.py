n=int(input())
li=list(map(int,input().split()))
a,b=map(int,input().split())
print(sum(li[a-1:b-1]))
