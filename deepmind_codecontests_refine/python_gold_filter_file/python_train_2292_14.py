n = int(input())
a = [0] + list(map(int, input().split()))
def max_heapify(a, i):
    global n
    l = 2 * i
    r = 2 * i + 1
    largest = l if l <= n and a[l] > a[i] else i
    if r <= n and a[r] > a[largest]:
        largest = r
    if largest != i:
        a[largest], a[i] = a[i], a[largest]
        max_heapify(a, largest)

for i in range(int(n / 2), 0, -1):
    max_heapify(a, i)
    
print(" " + " ".join(map(str, a[1:])))
