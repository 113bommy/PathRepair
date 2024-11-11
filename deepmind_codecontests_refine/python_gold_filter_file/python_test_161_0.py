import sys

def cont(task : dict, l, r):
    if (r-l) in task.keys():
        return (l,r) in task[r-l]
    else:
        return False

def checkandcont(task : dict, l, r, d, unused : set):
    if d in unused:
        return cont(task, l, r)
    else:
        return False

def solve(task : dict, n):
    unused = set(range(1,n+1))
    leng = 0
    dst = []
    while unused and leng < n+1:
        if leng in task.keys():
            for seg in task[leng]:
                l, r = seg
                if l == r:
                    dst.append([l, r, l])
                    unused.remove(l)
                else:
                    if checkandcont(task, l+1, r, l, unused):
                        dst.append([l, r, l])
                        unused.remove(l)
                    elif checkandcont(task, l, r-1, r, unused):
                        dst.append([l,r,r])
                        unused.remove(r)
                    else:
                        for d in range(l+1, r):
                            if d in unused and cont(task, d + 1, r) and cont(task, l, d-1):
                                dst.append([l,r,d])
                                unused.remove(d)
        leng += 1
    return dst


def put(task : dict, n, l, r):
    if r - l in task.keys():
        task[r-l].add((l,r))
    else:
        task[r-l] = set([(l,r)])

t = int(sys.stdin.readline())
for _ in range(t):
    n = int(sys.stdin.readline())
    task={}
    for _ in range(n):
        l, r = map(int,sys.stdin.readline().split(" "))
        put(task, n, l, r)
    dst = solve(task, n)
    for dstl in dst:
        dstls = " ".join(map(str, dstl))
        print(dstls)
    print()

