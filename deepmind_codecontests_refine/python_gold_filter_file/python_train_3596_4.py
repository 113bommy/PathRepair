n, x = map(int, input().split())
whoGive, whoTake = x, 0
for i in range(n):
    q = input()
    if q[0] == '-':
        if int(q[2:]) > whoGive:
            whoTake+=1
        else:
            whoGive-=int(q[2:])
    else:
        whoGive+=int(q[2:])
        
print(whoGive, whoTake)