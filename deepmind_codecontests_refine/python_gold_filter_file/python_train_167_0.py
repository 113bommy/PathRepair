import sys, math, os.path

FILE_INPUT = "e.in"
DEBUG = os.path.isfile(FILE_INPUT)
if DEBUG: 
    sys.stdin = open(FILE_INPUT)    

def ni():
    return map(int, input().split())

def nia(): 
    return list(map(int,input().split()))

def log(x):
    if (DEBUG):
        print(x)


n,m = ni()
a = [{i} for i in range(n)]
for i in range(m):
    x,y = ni()
    x,y = x-1, y-1
    a[x].add(y)
    a[y].add(x)
    # print(i)

# log(a)
q = []
willVisit = set(range(n))
# log(willVisit)
while willVisit:
    x = willVisit.pop()
    # loang tai x
    queue = [x]
    count = 1
    while queue:
        y = queue.pop()
        sibling = willVisit - a[y]
        count += len(sibling)
        queue.extend(sibling)
        willVisit -= sibling
        # count += 1
        # for z in willVisit:
        #     if (not z in a[y]):
        #         queue.add(z)
        # log(f" y = {y} - {willVisit} - {count} - {sibling}")
    # log(willVisit)
    q.append(count)

q.sort()
print(len(q))
print(" ".join(map(str,q)))

