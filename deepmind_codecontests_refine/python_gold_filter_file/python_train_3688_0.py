n=input()
s=list(map(int,input().split()))
a,b=map(int,input().split())
print(sum(s[a-1:b-1]))