class Node():
    def __init__(self, key):
        self.parent = None
        self.left = None
        self.right = None
        self.key = key

class Tree():
    def __init__(self):
        self.root = None
    def insert(self, key):
        z = Node(key)
        y = None
        x = self.root
        while x:
            y = x
            if z.key < x.key:
                x = x.left
            else:
                x = x.right
        z.parent = y
        
        if y == None:
            self.root = z
        elif z.key < y.key:
            y.left = z
        else:
            y.right = z
        
    def preorder(self, node):
        print(" {}".format(node.key), end = "")
        if node.left:
            self.preorder(node.left)
        if node.right:
            self.preorder(node.right)
            
    def inorder(self, node):
        if node.left:
            self.inorder(node.left)
        print(" {}".format(node.key), end = "")
        if node.right:
            self.inorder(node.right)
            
    def out(self):
        self.inorder(self.root)
        print('')
        self.preorder(self.root)
        print('')

tree = Tree()
N = int(input())
for _ in range(N):
    order = input().split()
    if order[0] == 'insert':
        tree.insert(int(order[1]))
    else:
        tree.out()