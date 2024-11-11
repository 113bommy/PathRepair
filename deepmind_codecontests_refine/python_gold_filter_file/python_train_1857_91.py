input()
l=sorted(list(map(int,input().split())))[::-1]
print(sum(l[::2])-sum(l[1::2]))