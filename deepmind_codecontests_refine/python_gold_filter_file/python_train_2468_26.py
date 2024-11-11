n=int(input())
b=list(map(int,input().split()))
b.sort()

print(b[(n-1)//2])
