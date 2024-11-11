from collections import Counter
from string import ascii_lowercase
num_names = int(input())
graph = {}
inCount = []
names = []
result = []



# create edge between first differing characters of neighboring names
def makeGraph():
    for index in range(1, num_names):
        prev_name = names[index - 1]
        curr_name = names[index]

        minlen = min(len(prev_name), len(curr_name))
        if (len(prev_name) > len(curr_name)
                and prev_name[:minlen] == curr_name):
            return False

        for j in range(0, minlen):
            a = prev_name[j]
            b = curr_name[j]
            if a != b:
                graph[a].append(b)
                inCount[ord(b) - ord('a')] += 1
                break
    return True

def topSort():
    queue = []
    count = 0
    for index in range(len(inCount)):
        if (inCount[index] == 0):
            queue.append(chr(index + ord('a')))
            count += 1
    while queue:
        curr = queue.pop(0)
        result.append(curr)
        for edge in graph[curr]:
            inCount[ord(edge) - ord('a')] -= 1
            if inCount[ord(edge) - ord('a')] == 0:
                queue.append(edge)
                count += 1
    return count == 26


for _ in range(num_names):
    names.append(input())
for c in ascii_lowercase:
    inCount.append(0)
    graph[c] = []
if makeGraph() and topSort():
    print(''.join(result))
else:
    print("Impossible")

