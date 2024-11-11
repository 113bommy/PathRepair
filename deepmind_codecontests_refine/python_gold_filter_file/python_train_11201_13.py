

n = int(input())

l = []

for i in range(n):
    l.append(list(map(int , input().split())))
    

for j in l:
    if j[0] != j[1]:
        print('rated')
        exit()

for m in range(n):
    for k in range(m):
        if l[m][0] > l[k][0]:
            print('unrated')
            exit()
            
print('maybe')
    