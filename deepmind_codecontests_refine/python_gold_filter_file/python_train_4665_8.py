n=int(input())
a=sorted(list(map(int, input().split())))
print(a[n//2]-a[n//2-1])