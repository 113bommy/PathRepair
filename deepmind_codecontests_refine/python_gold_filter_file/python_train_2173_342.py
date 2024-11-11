n,l = map(int,input().split())
L = [input() for _ in range(n)]
L.sort()
print("".join(L))