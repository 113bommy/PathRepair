inf = float("inf")
n=int(input())
time, val =[0], [0]
ans=[inf for i in range(n+1)]
ans[0]=0
for i in range(n):
    timeInp,valInp= [int(x) for x in input().split()]
    timeInp+=1#timeInp+=2
    time.append(timeInp)
    val.append(valInp)
for i in range(1,n+1):
    for j in range(n,0,-1):
        ans[j]=min(ans[j],ans[max(0,j-time[i])]+val[i])#(manter, pagarval[i] e liberar espaco)

print(ans[n])
