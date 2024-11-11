n,t=[int(x) for x in input().split()]
answer=10**100
total=0
for i in range(n):
    time,d=[int(x) for x in input().split()]
    if time<t:
        if (t-time)%d!=0:
            counter=t-(t-time)%d+d
        else:
            counter=t
    else:
        counter=time
    if counter<answer:
        answer=counter
        total=i+1
print(total)
