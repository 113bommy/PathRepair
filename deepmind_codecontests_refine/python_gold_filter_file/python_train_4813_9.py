triplets = []
for i in range(1,11000):
    for j in range(i,11000,i):
        for k in range(j,11000,j):
            triplets.append((i,j,k))

for _ in range(int(input())):
    a,b,c = map(int,input().split(" "))
    mini = 1e12;Ans = None
    for i,j,k in triplets:
        z = abs(a-i) + abs(b-j) + abs(c-k)
        if z<mini:
            mini = z;Ans = (i,j,k)
        if z==0:    break
    print(mini)
    print(*Ans)