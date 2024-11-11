n=int(input())
w=list(map(int,input().split()))
a,b=map(int,input().split())
print(sum(w[a-1:b-1]))
