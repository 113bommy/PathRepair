# -*- coding: utf-8 -*-
import sys
sys.setrecursionlimit(100000)

def insert(k, node):
    if k < node:
        if tree[node]["left"] == None:
            tree[node]["left"] = k
            tree[k] = {"parent": node, "left": None, "right": None}
            return
        else:
            insert(k, tree[node]["left"])
    else:
        if tree[node]["right"] == None:
            tree[node]["right"] = k
            tree[k] = {"parent": node, "left": None, "right": None}
            return
        else:
            insert(k, tree[node]["right"])


def pre_order(n):
    result = []
    if n == None:
        return []
    result.append(str(n))
    result.extend(pre_order(tree[n]["left"]))
    result.extend(pre_order(tree[n]["right"]))
    
    return result


def in_order(n):
    result = []
    
    if n == None:
        return []

    result.extend(in_order(tree[n]["left"]))
    result.append(str(n))
    result.extend(in_order(tree[n]["right"]))
    
    return result


M = int(input())
root = "nan"
while root == "nan":
    inp = [n for n in input().split()]
    if inp[0] == "print":
        print()
        print()
    else:
        root = int(inp[1])

tree = {root:{"parent": None, "left": None, "right": None}}

for i, _ in enumerate(range(M-1)):
    inp = [n for n in input().split()]
    if inp[0] == "print":
        in_text = ""
        pre_text = ""
        print(" " + " ".join(in_order(root)))
        print(" " + " ".join(pre_order(root)))
    else:
        insert(int(inp[1]), root)
        #if i%1000 == 0:
        #    print("done {}/{}".format(i, M))