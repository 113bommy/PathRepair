n, m = map(int, input().split())
words = dict()

for i in range(0, m):
    k, v = input().split()
    words[k] = v

print(" ".join(min(w, words[w], key = lambda o: len(o)) for w in input().split()))