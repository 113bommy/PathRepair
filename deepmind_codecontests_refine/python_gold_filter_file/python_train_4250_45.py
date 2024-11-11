A, B, K = map(int, input().split())
w = []
for i in range(1,101):
    if A%i==0 and B%i==0:
        w.append(i)
print(w[-K])