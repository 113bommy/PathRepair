 
d, n = map(int,input().split())
a = list(map(int, input().split()))

mas = [[] for _ in range(n+1)]

MOD = 1000000007
for _ in range(n-1):
    u, v = map(int,input().split())
    mas[u].append(v)
    mas[v].append(u)    
    
# #mas = [[],[2,3,10],[1,6,7],[1],[7],[9],[2],[2,4,11],[9],[5,8,10],[1,9,12],[7],[10]]
# mas = [[],[2,3],[1],[1,4],[3]]
# a = [0,2,1,3,2]

# d = 1

# print('mas:',mas)
# print('a:',a)

k = 0
def dfs(nomer,mas,tyt_yge_bili,f,nach):
    global k
    f[nomer] = 1;
    # print(nomer ,"--", nach)
    tyt_yge_bili[nomer] = True
    # f.append(a[nomer-1])
    # # print(f)
    # if max(f)-min(f)<=d:
    #     k+=1
    #     print(f)
    for j in mas[nomer]:
        if tyt_yge_bili[j]!=True:
            if not ((a[j-1] < a[nach-1]) or (a[j-1] > a[nach-1] + d)) and not ((a[j-1] == a[nach-1]) and (j < nach)):
                dfs(j,mas,tyt_yge_bili,f,nach)
                # print(a[j-1],a[nach-1])
                f[nomer] = (f[nomer] * (f[j] + 1)) % MOD
            
rez = 0
for z in range(1,n+1):
    f = []
    tyt_yge_bili = []
    for _ in range(n+1):
        f.append(0)
        tyt_yge_bili.append(0)
    dfs(z,mas,tyt_yge_bili,f , z)
    rez = (rez + f[z]) % MOD

print(rez)





    
