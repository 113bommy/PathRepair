if __name__ == '__main__':
    N = input()
    heap_array = [int(i) for i in input().split()]

    for i in range(len(heap_array)):
        print("node {}: key = {}, ".format(i+1, heap_array[i]), end='')
        if (i-1)//2 != -1 :
            print("parent key = {}, ".format(heap_array[(i-1)//2]), end='')
        if 2*i+1 < len(heap_array):
            print("left key = {}, ".format(heap_array[2*i+1]), end='')

        if 2*i+2 < len(heap_array):
            print("right key = {}, ".format(heap_array[2*i+2]), end='')
        print('')