m, n, k = map(int, input().split())
l = (n*m)//k
sw = 0
ans = []
temp = []

for i in range(n):
    if sw:
        for j in range(m):
            if len(temp) == l and len(ans) != k-1:
                ans.append(temp)
                temp = []

            temp.append((j+1, i+1))
    else:
        for j in range(m-1, -1, -1):
            if len(temp) == l and len(ans) != k-1:
                ans.append(temp)
                temp = []

            temp.append((j+1, i+1))
    sw ^= 1
ans.append(temp)

for i in ans:
    print(len(i), end=" ")
    st = ""
    for j in i:
        st += str(j[0]) + " " + str(j[1]) + " "
    print(st)
    
#     print(i)