K,S=map(int, input().split())
print(len([1 for x in range(K+1) for y in range(K+1) if 0<=S-x-y<=K]))