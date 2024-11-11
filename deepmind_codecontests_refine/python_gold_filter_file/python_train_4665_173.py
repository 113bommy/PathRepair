a=int(input())
n=sorted(list(map(int,input().split())))
print(n[a//2]-n[a//2-1])
