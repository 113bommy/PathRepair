n = int(input())
l = sorted(list(map(int,input().split())))
a = 0
for i in range(0,len(l),2):
    a += l[i]
print(a)