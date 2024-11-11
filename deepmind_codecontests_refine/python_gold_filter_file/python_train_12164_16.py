ADJ = 10**2
n = int(input())
ts = list(map(int, input().split()))
vs = list(map(int, input().split()))
for i in range(n):
    ts[i] *= ADJ
    vs[i] *= ADJ
tt = sum(ts)
vss = [0]*tt
j = 0
cnt = 0
for i in range(tt):
    vss[i] = vs[j]
    cnt += 1
    if cnt == ts[j]:
        j += 1
        cnt = 0
#print(vss)
max_speed = 1
max_speeds = [0]*tt
for i in reversed(range(tt-1)):
    max_speeds[i] = min(max_speed,vss[i],vss[i+1],max_speeds[i+1]+1)
    max_speed += 1
#print(max_speeds)
cv = 0
for i in range(tt):
    if cv < max_speeds[i]:
        cv += 1
    elif cv == max_speeds[i]:
        pass
    else:
        cv -= 1
    vss[i] = cv
#print(vss)
res = 0
for i in range(tt):
    if i == 0:
        res += vss[i] / 2
    else:
        if vss[i] >= vss[i-1]:
            res += vss[i-1] + (vss[i] - vss[i-1]) / 2
        else:
            res += (vss[i-1] - vss[i]) / 2 + vss[i]
    #print()
    #print(str(i)+" "+str(res))
print(res/ADJ/ADJ)