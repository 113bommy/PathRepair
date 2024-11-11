import sys
from math import sqrt
from collections import defaultdict
inpt = sys.stdin.readline

def inp():
    return(int(inpt()))

def inlist():
    return(list(map(int,inpt().split())))

def instr():
    s = inpt()
    return(list(s[:len(s)-1]))

def invr():
    return(map(int,inpt().split()))

class Graph:

    def __init__(self,n):
        self.n = n
        self.graph = defaultdict(list)
        self.marked = defaultdict(int)
    
    def addEdge(self,u,v):
        self.graph[u].append(v)
        self.graph[v].append(u)

    def dfs(self,u):

        self.marked[u] = 1

        for i in self.graph[u]:
            if(self.marked[i] == 0):
                self.dfs(i)

def main():
        
        t = inp()

        for l in range(t):

            n = inp()

            a = instr()
            b = instr()

            g = Graph(20)

            np = False

            for i in range(n):
                x = ord(a[i])-96
                y = ord(b[i])-96
                if(x>y):
                    print(-1)
                    np = True
                    break
                g.addEdge(x,y)
            
            if(np == False):
                ans = 20

                for i in range(1,21):
                    if(g.marked[i] == 0):
                        g.dfs(i)
                        ans -= 1

                print(ans)

main() 

