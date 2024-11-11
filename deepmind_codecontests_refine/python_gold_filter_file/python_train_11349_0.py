class Node:
    def __init__(self, key):
        self.key = key
        self.parent = None
        self.left = None
        self.right = None
class Tree:
    def __init__(self):
        self.root = None
        self.inorder = []
        self.preorder = []

    def insert(self, node):

        p = None
        x = self.root        
        while x is not None:
            p = x
            # print(node.key, x.key)
            if node.key <= x.key:
                x = x.left
            else:
                x = x.right

        # insertするnodeの親を設定
        node.parent = p

        if p is None:
            self.root = node
        else:
            # insertするnodeを親のleftかrightに設定
            if node.key <= p.key:
                # print('leftに設定')
                p.left = node
            else:
                # print('rightに設定')
                p.right = node

    def find(self, key):
        # print('find: ', str(key))
        node = self.root
        while node is not None:
            if node.key == key:
                return node
            elif key <= node.key:
                node = node.left
            else:
                node = node.right
        return None

    def delete(self, z):
        # print("delete =========", z.key)
        # print(z.key)
        # print(z.parent)
        p = z.parent
        # print(p.key)

        # 1. zが子を持たない場合
        if z.left is None and z.right is None:
            # print('pattern 1')
            if p.left == z:
                p.left = None
            else:
                p.right = None

        # 3. zが子を2つ持つ場合
        elif z.left is not None and z.right is not None:
            # print('pattern 2')
            next_node = tree.get_next_node(z)
            # print('next:', next_node.key)
            z.key = next_node.key
            self.delete(next_node)

        # 2. zがちょうど1つの子を持つ場合
        else:
            # print('pattern 3')
            # zが左子だった場合
            if p.left == z:
                if z.left is not None:
                    p.left = z.left
                    z.left.parent = p
                else:
                    p.left = z.right
                    z.right.parent = p
            else:
                # zが右子だった場合
                if z.left is not None:
                    p.right = z.left
                    z.left.parent = p
                else:
                    p.right = z.right
                    z.right.parent = p

    def get_next_node(self, node):
        if node.right is not None:
            # print('node right is not none')
            return self.get_minimum(node.right)
        p = x.parent
        while p is not None and p != p.parent.left:
            p = p.parent
        return p.parent

    def get_minimum(self, node):
        x = node
        # print('find1 :', x.key)
        while x.left is not None:
            x = x.left
            # print('find2 :', x.key)
        return x

    def print_inorder(self):
        self.inorder = []
        self.inorder_traverse(self.root)
        print(' ' + ' '.join(map(str, self.inorder)))

    def print_preorder(self):
        self.preorder = []
        self.preorder_traverse(self.root)
        print(' ' + ' '.join(map(str, self.preorder)))

    def inorder_traverse(self, node):
        if node is None:
            return
        self.inorder_traverse(node.left)
        self.inorder.append(node.key)
        self.inorder_traverse(node.right)

    def preorder_traverse(self, node):
        if node is None:
            return
        self.preorder.append(node.key)
        self.preorder_traverse(node.left)
        self.preorder_traverse(node.right)

tree = Tree()
m = int(input())
for i in range(m):
    line = input().split()
    if line[0] == 'print':
        # print('root', str(tree.root.key))
        tree.print_inorder()
        tree.print_preorder()
        # print('root:(30)', tree.root.key)
        # print('root.left(17):', tree.root.left.key)
        # print('root.left.left(X):', tree.root.left.left.key)
        # print('root.left.right(X):', tree.root.left.right.key)
        # print('-----------------')
    elif line[0] == 'insert':
        key = int(line[1])
        tree.insert(Node(key))
    elif line[0] == 'find':
        key = int(line[1])
        if tree.find(key):
            print('yes')
        else:
            print('no')
    elif line[0] == 'delete':
        
        # print("current tree----")
        # print(tree.root.key)
        # print(tree.root.left.key)
        # print(tree.root.left.right.key)
        # print(tree.root.left.right.parent.key)
        # print("current tree----")
        key = int(line[1])
        # print('delete', str(key))
        node = tree.find(key)
        # print('node.key', node.key)
        tree.delete(node)



# print('root.left.right:', tree.root.left.right.left.key)
# print('root:', tree.root.left.right.right.key)
