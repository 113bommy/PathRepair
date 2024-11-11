from collections import defaultdict
n, m= map(int, input("").split())

class Graph():
    def __init__(self):
        self.nodes = {i:Node(i) for i in range(1, n + 1)}

    def find(self, i):
        if self.nodes[i].parent_id != i:
            new_parent_id = self.find(self.nodes[i].parent_id)
            self.nodes[i].change_parent_id(new_parent_id)
        return self.nodes[i].parent_id

    def union(self, i, j, count,is_cycle = False, ):
        i_parent_id = self.find(i)
        j_parent_id = self.find(j)
        if i_parent_id != j_parent_id:
            count -= 1
            if self.nodes[i_parent_id].rank > self.nodes[j_parent_id].rank:
                self.nodes[j_parent_id].change_parent_id(i_parent_id)
            else:
                self.nodes[i_parent_id].change_parent_id(j_parent_id)
                if self.nodes[i_parent_id].rank == self.nodes[j_parent_id].rank:
                    self.nodes[i_parent_id].change_rank(self.nodes[j_parent_id].rank + 1)
            return is_cycle, count
        is_cycle = True
        return is_cycle, count


class Node():
    def __init__(self, id):
        self.id = id
        self.parent_id = id
        self.rank = 0

    def change_parent_id(self, new_parent_id):
        self.parent_id = new_parent_id

    def change_rank(self, new_rank):
        self.rank = new_rank

graph = Graph()
num_cycles = 0
count = n
for i in range(m):
    a, b = map(int, input("").split())
    is_cylce, count = graph.union(a, b, count)
    if is_cylce:
        num_cycles += 1


if num_cycles == 1 and count == 1:
    print('FHTAGN!')
else:
    print('NO')


