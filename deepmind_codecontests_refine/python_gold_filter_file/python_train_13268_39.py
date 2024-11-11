l = []
for _ in range(int(input())):
    l.append(list(map(int,input().split())))
count = 0
for i in range(0,len(l)):
    for j in range(0,len(l[i])-1):
        if l[i][j+1]-l[i][j] >= 2:
            count = count + 1
        else:
            count = count
print(count)
