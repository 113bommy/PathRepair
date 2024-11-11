from heapq import heapify,heappush,heappop

n = int(input())
sex = input()
a = [int(i) for i in input().split()]
cp = []
r = []
b = sex.count('B')
N = min(n-b,b)
for i in range(1,len(a)):
    if sex[i] != sex[i-1]:
        cp.append((abs(a[i]-a[i-1]),i-1,i))
heapify(cp)
prev = [i for i in range(-1,len(sex))]
nxt = [i for i in range(1,len(sex)+2)]
trace = [0 for i in range(len(sex))]
cnt = 0
while cnt < N:
    temp = heappop(cp)
    x,y = temp[1],temp[2]
    if trace[x] or trace[y]:
        continue
    r.append(str(x+1)+' '+str(y+1))
    cnt += 1
    trace[x],trace[y] = 1,1
    if prev[x] != -1 and nxt[y] != len(a):
        nxt[prev[x]] = nxt[y]
        prev[nxt[y]] = prev[x]
        if sex[prev[x]] != sex[nxt[y]]:
            heappush(cp,(abs(a[prev[x]]-a[nxt[y]]),prev[x],nxt[y]))

print(len(r))
print('\n'.join(r))
