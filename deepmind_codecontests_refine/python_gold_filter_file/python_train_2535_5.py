n = int(input())

s = str(n) + " " + " ".join(list(map(str, list(range(1, n)))))
print(s)