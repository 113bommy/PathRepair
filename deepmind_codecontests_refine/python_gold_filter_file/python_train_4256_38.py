N = int(input())
Ls = list(map(int, input().split()))
Ls.sort()
print(sum(Ls[0::2]))