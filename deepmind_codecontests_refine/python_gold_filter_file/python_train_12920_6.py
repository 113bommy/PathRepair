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
    for _ in range(get_int()):
        lcase = list()
        ucase = list()
        digit = list()
        st = list(stdin.readline().strip())
        j = 0
        for i in st:
            if str(i).isupper():
                ucase.append(j)
            elif str(i).islower():
                lcase.append(j)
            else: digit.append(j)
            j+=1
        if len(ucase)==0:
            if len(lcase)>1:
                st[lcase[0]] = "J"
                lcase.pop(0)
            else:
                st[digit[0]] = "K"
                digit.pop(0)
        if len(lcase)==0:
            if len(ucase)>1:
                st[ucase[0]] = "j"
                ucase.pop(0)
            else:
                st[digit[0]] = "k"
                digit.pop(0)
        if len(digit)==0:
            if len(lcase)>1:
                st[lcase[0]] = "1"
            else:
                st[ucase[0]] = "0"
        display("".join(st))


# --------------------------------------------------------------------------------------------- END


cProfile.run('main()') if test else main()