alpha_small_dict = {chr(i):i-97 for i in range(97, 97+26)} #辞書ver
n = int(input())
s = input()
data = [alpha_small_dict[x] for x in s]


G = [[] for _ in range(n)]
alpha_data = [[] for _ in range(26)]
for i,x in enumerate(data):
    for y in range(x+1,26):
        for j in alpha_data[y]:
            G[i].append(j)
            G[j].append(i)
    alpha_data[x].append(i)

color = [-1 for _ in range(n)]
t = True
for i in range(n):
    if color[i] == -1:
        que = [[-1,i]]
        color[i] = 0
        while que:
            pre,now = que.pop()
            for to in G[now]:
                if to == pre:continue
                if color[to] == color[now]:
                    print("NO")
                    exit()
                elif color[to] == -1:
                    color[to] = 1 - color[now]
                    que.append([now,to])
print("YES")
for x in color:
    print(x,end="")
print()