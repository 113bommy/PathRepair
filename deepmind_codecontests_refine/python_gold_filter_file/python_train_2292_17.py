def max_heapify(A, i):
  l = i * 2
  r = l + 1
  largest = i
  if l <= H and A[l] > A[i]: largest = l
  if r <= H and A[r] > A[largest]: largest = r
  if largest != i:
    A[i], A[largest] = A[largest], A[i]
    max_heapify(A, largest)

def build_max_heap(A):
  for i in range(H // 2, 0, -1):
    max_heapify(A, i)

H = int(input())
A = list(map(int, input().split()))
A.insert(0, 0)
build_max_heap(A)

print(" " + " ".join(map(str, A[1:])))