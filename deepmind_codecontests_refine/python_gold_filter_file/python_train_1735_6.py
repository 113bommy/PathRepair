n = int(input())
a = list(map(int,input().split()))
b =[0 for i in range(105)]
ok = False
def dfs(now,ans):
    global ok
    global b
    if(ans==n):
        ok=True
        b[ans]=now
        return
    if(now%3==0 and now//3 in a):
        dfs(now//3,ans+1)
    if(ok):
        b[ans]=now
        return
    if(now*2 in a):
        dfs(now*2,ans+1)
    if(ok):
        b[ans]=now
        return
    return
for i in range(n):
    dfs(a[i],1)
    if(ok):
        break
for i in range(n-1):
    print(b[i+1],end=' ')
print(b[n])

