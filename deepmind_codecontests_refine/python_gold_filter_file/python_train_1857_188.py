N = input()
n = list(map(int, input().split()))
n.sort(reverse=True)
print(sum(n[::2])-sum(n[1::2]))