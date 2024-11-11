input()
l = sorted(list(map(int,input().split())))
print(sum(l[::-2])-sum(l[-2::-2]))