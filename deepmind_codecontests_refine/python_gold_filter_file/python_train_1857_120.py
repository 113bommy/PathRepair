N = int(input())
A = sorted(list(map(int, input().split())))
print(sum(A[-1::-2])-sum(A[-2::-2]))
