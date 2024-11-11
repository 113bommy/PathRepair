from sys import stdin, stdout
import cProfile, math
from collections import Counter

printHeap = str()
test = False
memory_constrained = False


def display(string_to_print):
    stdout.write(str(string_to_print) + "\n")


def test_print(output):
    if test:
        stdout.write(str(output) + "\n")


def display_list(list1, sep=" "):
    stdout.write(sep.join(map(str, list1)) + "\n")


def get_int():
    return int(stdin.readline().strip())


def get_tuple():
    return map(int, stdin.readline().split())


def get_list():
    return list(map(int, stdin.readline().split()))

def rotate (l, offset=1):
    return l[offset:] + l[:offset]
memory = dict()

def clear_cache():
    global memory
    memory = dict()


def cached_fn(fn, *args):
    global memory
    if args in memory:
        return memory[args]
    else:
        result = fn(*args)
        memory[args] = result
        return result


# ----------------------------------------------------------------------------------- MAIN PROGRAM

def main():
    n, l = get_tuple()
    l1 = get_list()
    l2 = get_list()
    d1,d2 = list(),[]
    for i,ele in enumerate(l1):
    	if (i+1!=len(l1)):
    		d1.append(l1[i+1]-ele)
    d1.append(l-l1[-1]+l1[0])
    for i,ele in enumerate(l2):
    	if (i+1!=len(l2)):
    		d2.append(l2[i+1]-ele)
    d2.append(l-l2[-1]+l2[0])
    for i in range(len(d1)):
        d2 = rotate(d2)
        if (d1==d2 or (len(l1)==1 and len(l2)==1)):
            display("YES")
            return
    display("NO")

# --------------------------------------------------------------------------------------------- END


cProfile.run('main()') if test else main()
