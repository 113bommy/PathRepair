n, m = map(int,input().split())
if n-m == 1:
    print(0)
    exit()
a = list(map(int,input().split()))
way = [[] for i in range(n)]
for i in range(m):
    x,y = map(int,input().split())
    way[x].append(y)
    way[y].append(x)

#グラフをグループ化するやつ
import queue
def grouping(n,arr):
    gr = []
    al = [-1 for i in range(n)]
    q = queue.Queue()
    for i in range(n):
        if al[i] == 0:
            continue
        else:
            gi = []
            q.put(i)
            al[i] = 0
            while not q.empty():
                qi = q.get()
                gi.append(qi)
                for ai in arr[qi]:
                    if al[ai] < 0:
                        q.put(ai)
                        al[ai] = 0
            gr.append(gi)
    return gr

grp = grouping(n,way)
if len(grp)-2 > n-len(grp):
    print("Impossible")
    exit()
o2 = [0 for i in range(n-len(grp))]
o1 = [0 for i in range(len(grp))]
i1 = 0

for j,gi in enumerate(grp):
    m = 10**10
    f = True
    for i in gi:
        if m > a[i]:
            if f:
                f = False
            else:
                o2[i1] = m
                i1 += 1
            m = a[i]
        else:
            o2[i1] = a[i]
            i1 += 1
    o1[j] = m

o2.sort()
ans = sum(o1)
for i in range(len(o1)-2):
    ans += o2[i]
print(ans)
