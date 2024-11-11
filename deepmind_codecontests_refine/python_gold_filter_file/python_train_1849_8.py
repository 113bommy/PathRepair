k = int(input())
s = []
Total = set()
for i in range(k):
    n = int(input())
    s.append(list(map(int, input().split())))
    X = sum(s[i])
    for j in range(len(s[i])):
        if (i, X-s[i][j]) not in Total:
            Total.add((i, X-s[i][j]))
            Total.add((i, j, X-s[i][j]))
 
flag = True
test = []
for i in Total:
    if len(i) == 3:
        test.append(i)
test.sort(key=lambda x: x[2])
for i in range(len(test)-1):
    if test[i][2] == test[i+1][2]:
        if test[i][0] != test[i+1][0]:
            print("YES")
            print(test[i][0]+1, test[i][1]+1)
            print(test[i+1][0] + 1, test[i+1][1] + 1)
            flag = False
            break
 
if flag:
    print("NO")