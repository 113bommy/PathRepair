import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

n,m = map(int,readline().split())
data = list(map(int,read().split()))

links = [[] for _ in range(n+1)]
it = iter(data)
for a,b in zip(it,it):
    links[a].append(b)
    links[b].append(a)

color = [-1] * (n+1)
color[1] = 0
stack = [1]
while(stack):
    i = stack.pop()
    ci = color[i]
    for j in links[i]:
        if(color[j] == -1):
            color[j] = 1-ci
            stack.append(j)
        else:
            if(color[j]==ci):
                ans = (n*(n-1))//2 - m
                print(ans)
                exit()

n0 = color.count(0)
n1 = color.count(1)
ans = n0*n1 - m
print(ans)