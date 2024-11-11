#Lights Out
#Problem Link : http://codeforces.com/problemset/problem/275/A

res = list()
res.append([0 , 0 , 0 , 0 , 0])

for i in range(1 , 4):
    res.append([0 , 0 , 0 , 0 , 0])
    res[i][1] , res[i][2] , res[i][3] = map(int , input().split())
res.append([0 , 0 , 0 , 0 , 0])

for i in range(1 , 4):
    for j in range(1 , 4):
        print(1 - (res[i][j] + res[i-1][j] + res[i][j-1] + res[i+1][j] + res[i][j+1])%2 , end='')
    print()