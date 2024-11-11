
def heapify(a, i):
    left = 2 * i + 1
    right = 2 * i + 2
    largest = i

    if left < len(a) and a[left] > a[largest]:
        largest = left
    if right < len(a) and a[right] > a[largest]:
        largest = right

    if largest != i:
        a[largest], a[i] = a[i], a[largest]
        heapify(a, largest)

def build_heap(a):
    heap = a[::]
    for i in range(len(a) // 2)[::-1]:
        heapify(heap, i)
    return heap

def decrease_root(a, value):
    a[0] = abs(abs(a[0]) - value)
    heapify(a, 0)


if __name__ == '__main__':
    n, k1, k2 = [int(x) for x in input().split()]
    a = [int(x) for x in input().split()]
    b = [int(x) for x in input().split()]

    delta_heap = build_heap([abs(a[i] - b[i]) for i in range(len(a))])

    k = k1 + k2

    while k > 0:
        decrease_root(delta_heap, 1)
        k -= 1

    print(sum([delta_heap[i] ** 2 for i in range(len(delta_heap))]))