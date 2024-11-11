from queue import deque
from sys import setrecursionlimit
setrecursionlimit(10**6)

class Graph:
    '''A graph has a set of vertices and a set of edges, with each
    edge being an ordered pair of vertices. '''

    def __init__ (self):
        self._alist = {}

    def add_vertex (self, vertex):
        ''' Adds 'vertex' to the graph
        Preconditions: None
        Postconditions: self.is_vertex(vertex) -> True
        '''
        if vertex not in self._alist:
            self._alist[vertex] = set()

    def add_edge (self, source, destination):
        ''' Adds the edge (source, destination)
        Preconditions: None
        Postconditions:
        self.is_vertex(source) -> True,
        self.is_vertex(destination),
        self.is_edge(source, destination) -> True
        '''
        self.add_vertex(source)
        self.add_vertex(destination)
        self._alist[source].add(destination)

    def is_edge (self, source, destination):
        '''Checks whether (source, destination) is an edge
        '''
        return (self.is_vertex(source)
                and destination in self._alist[source])

    def is_vertex (self, vertex):
        '''Checks whether vertex is in the graph.
        '''
        return vertex in self._alist

    def neighbours (self, vertex):
        '''Returns the set of neighbours of vertex. DO NOT MUTATE
        THIS SET.
        Precondition: self.is_vertex(vertex) -> True
        '''
        return self._alist[vertex]

    def vertices (self):
        '''Returns a set-like container of the vertices of this
        graph.'''
        return self._alist.keys()


class UndirectedGraph (Graph):
    '''An undirected graph has edges that are unordered pairs of
    vertices; in other words, an edge from A to B is the same as one
    from B to A.'''

    def add_edge (self, a, b):
        '''We implement this as a directed graph where every edge has its
        opposite also added to the graph'''
        super().add_edge (a, b)
        super().add_edge (b, a)


def dfsFindLoop(g, v):
    reached = {}
    foundLoop = False;
    
    def do_dfs(curr, prev, dist):
        nonlocal foundLoop
        
        if curr == v and dist > 2:
            foundLoop = True
        if curr in reached:
            return
        
        reached[curr] = prev
        for succ in g.neighbours(curr):
            do_dfs(succ, curr, dist+1)

    do_dfs(v, v, 0)
    return foundLoop

def findLoop(letter, array, n, m):
    #find loops for selected letter
    g = UndirectedGraph()
    
    #construct graph
    i, j = 0, 0
    while i < n:
        j=0
        while j < m:
            l = array[i][j]
            if l == letter:
                #add neighbors: up down left right
                if i-1 >= 0 and array[i-1][j] == l:
                    g.add_edge((i, j), (i-1, j))
                if i+1 < n and array[i+1][j] == l:
                    g.add_edge((i, j), (i+1, j))
                if j-1 >= 0 and array[i][j-1] == l:
                    g.add_edge((i, j), (i, j-1))
                if j+1 < m and array[i][j+1] == l:
                    g.add_edge((i, j), (i, j+1))
            j+=1
        i+=1
    
    verts = g.vertices()
    for vert in verts:
        if dfsFindLoop(g, vert):
            return True
    
    return False


n,m = map(int, input().split())    
array = [list(input()) for x in range(n)]

searchedLetters = {}
    
i, j = 0, 0
found = False
while i < n and not found:
    j=0
    while j < m and not found:
        letter = array[i][j]
        if letter not in searchedLetters:
            f = findLoop(letter, array, n, m)
            if found == False: found = f
            searchedLetters[letter] = 1;
        j+=1
    i+=1

if found:
    print("Yes")
else:
    print("No")







