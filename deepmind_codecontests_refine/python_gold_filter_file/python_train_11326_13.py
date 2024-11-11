H, W, A, B = map(int, open(0).read().split())

S = [["01"[(i < B) ^ (j < A)] for j in range(W)] for i in range(H)]
print("\n".join("".join(s) for s in S))
