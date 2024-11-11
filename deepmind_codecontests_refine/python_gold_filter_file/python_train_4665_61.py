n=int(input())
p=sorted(map(int, input().split()))
print(p[n//2]-p[n//2-1])