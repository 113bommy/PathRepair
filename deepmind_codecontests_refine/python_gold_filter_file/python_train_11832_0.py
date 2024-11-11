import sys
import re

SEPARATORS = "[.,? !'-]"

class TrieNode(object):
    def __init__(self):
        self.terminal = False
        self.go = {}
        self.count = 0

def insert(node, s):
    nodes = [node]
    unique, auto = 0, 0
    for c in s:
        if c not in node.go:
            node.go[c] = TrieNode()
        node = node.go[c]
        nodes.append(node)
        
        if node.count == 1:
            unique += 1
        if node.terminal:
            auto = max(unique - 2, 0)
            
    if not node.terminal:
        node.terminal = True
        for node in nodes:
            node.count += 1
    return auto

root = TrieNode()
answer = 0
for line in sys.stdin:
    answer += len(line)
    for word in filter(None, re.split(SEPARATORS, line.strip())):
        answer -= insert(root, word)
print(answer)
