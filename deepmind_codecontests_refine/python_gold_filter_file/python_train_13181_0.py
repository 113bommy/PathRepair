inp= map(int,input().split())

n,k= inp

a= [list(map(int,input().split())) for _ in range(n)]

found = [False]*(1<<k)

done = False 

for i in a:
    val = 0
    for j in i:
        val*=2
        val+=j 
    if val ==0:
        done = True 
    for j in range(len(found)):
        if j & val ==0 and found[j]:
            done = True 
    found[val]=True 
print("Yes" if done else "No")
        