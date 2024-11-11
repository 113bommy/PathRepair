pr=[True]*50100
for i in range(2,225):
    if pr[i]:
        for j in range(i*2,50100,i):
            pr[j]=False

while True:
    try:
        n=int(input())
    except:
        break
    for i in range(n-1,0,-1):
        if pr[i]:
            print(i,end=" ")
            break
    for i in range(n+1,50100):
        if pr[i]:
            print(i)
            break