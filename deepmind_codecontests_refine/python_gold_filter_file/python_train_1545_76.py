n=int(input())
blue=[input() for i in range(n)]
m=int(input())
red=[input() for i in range(m)]
print(max(max([blue.count(blue[i])-red.count(blue[i]) for i in range(n)]),0))