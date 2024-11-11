n = int(input())
d = sorted(map(int, input().split()))
print(d[len(d)//2]-d[len(d)//2-1])