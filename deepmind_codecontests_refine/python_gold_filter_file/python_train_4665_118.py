a=int(input())
b=sorted(list(map(int,input().split())))
print(b[a//2]-b[a//2-1])