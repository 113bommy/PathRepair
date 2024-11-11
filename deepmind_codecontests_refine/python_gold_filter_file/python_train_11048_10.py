n = int(input())
obs = []
clues = []
for i in range(n):
    x,y = map(int, input().split())
    obs.append([x,y])
for i in range(n):
    x,y = map(int, input().split())
    clues.append([x,y])
obs = sorted(obs, key = lambda x:x[0]+x[1]+x[1])
clues = sorted(clues, key = lambda x:x[0]+x[1]+x[1], reverse = True)
print(obs[0][0]+clues[0][0], obs[0][1]+clues[0][1])
