n=int(input())
a=sorted(list(map(int,input().split())) for _ in range(n))
print(sum(a[-1]))