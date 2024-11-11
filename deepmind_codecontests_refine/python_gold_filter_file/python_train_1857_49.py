input();
al=[int(i) for i in input().split()]
al.sort()
al = al[::-1]
print(sum(al[::2])-sum(al[1::2]))