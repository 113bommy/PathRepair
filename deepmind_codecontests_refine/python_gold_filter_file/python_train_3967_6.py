from sys import stdin, stdout
import cProfile

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
    return int(stdin.readline())


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
    n, m = get_tuple()
    for _ in range(n-1):
        print(8, end="")
    print(9)
    for _ in range(n):
        print(1,end="")


# --------------------------------------------------------------------------------------------- END


cProfile.run('main()') if test else main()
