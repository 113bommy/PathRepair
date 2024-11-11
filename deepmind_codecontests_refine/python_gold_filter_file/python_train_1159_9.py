n = int(input())
an = list(map(int,input().split()))
an.sort()
print(*an[::2]+an[1::2][::-1])