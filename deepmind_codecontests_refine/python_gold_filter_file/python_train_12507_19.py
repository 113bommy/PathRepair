a=[int(input().split()[1])for _ in range(int(input()))]
k=int(input())
print(sum(x>=k for x in a))
