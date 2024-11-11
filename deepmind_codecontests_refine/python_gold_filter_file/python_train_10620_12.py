import sys

class Node:
    __slots__ = ['key', 'left', 'right']
    def __init__(self, key):
        self.key = key
        self.left = self.right = None

class BST:
    def __init__(self):
        self.root = None
    def insert(self, key):
        x, y = self.root, None
        while x != None: x, y = x.left if key < x.key else x.right, x
        if y == None: self.root = Node(key)
        elif key < y.key: y.left = Node(key)
        else: y.right = Node(key)
    def print_tree(self):
        def inorder(node):
            return inorder(node.left) + f' {node.key}' + inorder(node.right) if node else ''
        def preorder(node):
            return f' {node.key}' + preorder(node.left) + preorder(node.right) if node else ''
        print(inorder(self.root))
        print(preorder(self.root))

tree = BST()
input()
for e in sys.stdin:
    if e[0] == 'i': tree.insert(int(e[7:]))
    else: tree.print_tree()
