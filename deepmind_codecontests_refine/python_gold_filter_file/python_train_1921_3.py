"""
Graph Implementation
"""

class Graph(object):
    def __init__(self, num_nodes):
        self.num_nodes = num_nodes
        self.adj_list = {}

    def add_edge(self, a, b):
        if a in self.adj_list:
            if b not in self.adj_list[a]:
                self.adj_list[a].append(b)
        else:
            self.adj_list[a] = []
            self.adj_list[a].append(b)

        if b in self.adj_list:
            if a not in self.adj_list[b]:
                self.adj_list[b].append(a)
        else:
            self.adj_list[b] = []
            self.adj_list[b].append(a)

    def generate_freq_dict(self):
        freq_dict = {}
        for k,v in self.adj_list.items():
            freq_dict[k] = len(v)
        return freq_dict

    def generate_sorted_freq_dict(self):
        freq_dict = self.generate_freq_dict()
        sfd = [(k, freq_dict[k]) for k in sorted(freq_dict, key=freq_dict.get, reverse=True)]
        return sfd

    def print_graph(self):
        print(self.adj_list)

    def get_sfd_with_src(self, src):
        freq_dict = self.generate_freq_dict()
        sfd = [(k, freq_dict[k]) for k in sorted(freq_dict, key=freq_dict.get, reverse=True) if k in self.adj_list[src]]
        return sfd

def read_graph():
    n,m = map(int, input().split())
    g = Graph(n)
    for _ in range(m):
        a,b = map(int, input().split())
        g.add_edge(a,b)
    return g
    #g.print_graph()
    #sfd = g.generate_sorted_freq_dict()

def rec_dfs(g, top, visited, d):
    visited[top] = True
    src_sfd = g.get_sfd_with_src(top)
    for x in src_sfd:
        next = x[0]
        if not visited[next]:
            d[0] = d[0] * 2
            rec_dfs(g, next, visited, d)


def dfs():
    g = read_graph()
    #g.print_graph()
    sfd = g.generate_sorted_freq_dict()
    d = [1]
    visited = {}
    for i in range(1, g.num_nodes + 1):
        visited[i] = False

    while len(sfd) > 0:
        top = sfd.pop()[0]
        if not visited[top]:
            rec_dfs(g, top, visited, d)
    #print("*"*20)
    #print("DFS complete")
    #print(d)
    print(d[0])


dfs()