n, m  = map(int, input().split())
languages = []
for i in range(n):
  languages.append(list(map(int, input().split()))[1:])
languages.insert(0, [])


# print(languages)

neighbors = [[] for i in range( 1 + n)]
# Function to check if employees speak same language

def SpeakSame(e1, e2):
  for one_language in languages[e1]:
    for another_language in languages[e2]:
      if one_language == another_language:
        return True
  return False

# For each employee

for i in range(1, 1 + n):
  for j in range( 1 + i, 1 + n):
    if SpeakSame(i, j):
      neighbors[i].append(j)
      neighbors[j].append(i)

# 2 edges and 3 vertices
# V is the number of vertices
# E is the number of edges
# Adjacency list
# initialize
# E = int(input())
# V = 1 + E
# neighbors = [[] for i in range(1 + V)]
# for i in range(E):
#   n, m = map(int, input().split())
#   neighbors[n].append(m)
#   neighbors[m].append(n)

result = [[], [2, 3], [1], [1]]
# assert neighbors==result
# print(neighbors)

class Queue:
    def __init__(self):
        self.list = []

    def push(self, value):
        self.list.append(value)

    def pop(self):
        return self.list.pop(0)

    def top(self):
        return self.list[0]

    def empty(self):
        return len(self.list) == 0


visited = [False for i in range(1+n)]
independentCycles = 0
def BFS(starting):
    connectedComponent = []
    global independentCycles
    BFSq = Queue()
    BFSq.push(starting)
    visited[starting] = True
    while not BFSq.empty():
        m = BFSq.pop() # we rely on the fact that pop() also return the popped element
        connectedComponent.append(m)
        for neighbor in neighbors[m]:
            if not visited[neighbor]:
                # the m -> neighbor edged is the subtree
                visited[neighbor] = True
                BFSq.push(neighbor)
            else:
                # the m -> neighbor edged is closing an independent loop
                independentCycles += 1
    return connectedComponent


count_isolated =0
ConnectedSets = []
for idx, visit in enumerate(visited):
    if visit == False:
        connectedComponent = BFS(idx)
        if len(connectedComponent)==1:
          count_isolated +=1
        ConnectedSets.append(connectedComponent)
doNotSpeak = 0
for language in languages:
  if len(language)==0:
    doNotSpeak +=1
# print(doNotSpeak)
if doNotSpeak == len(languages):
  print(len(ConnectedSets)-1)
  
else:
  print(len(ConnectedSets)-2)
